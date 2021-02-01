class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int res = INT_MAX;
        set<int> pre{arr[0]};
        for (int num : arr) {
            set<int> cur{num};
            res = min(res, abs(num - target));
            for (int i : pre) {
                cur.insert(i & num);
                res = min(res, abs((i & num) - target));
            }
            pre = std::move(cur);
        }
        return res;
    }
};



////////////////////////////////以下未看//////////////////////////////

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int len = (int)arr.size();
        vector<vector<int> > tab(30);
        for(int i = 0; i < len; i++)
            for(int j = 0; j < 30; j++) if((arr[i] >> j) & 1)
                tab[j].push_back(i);

        vector<int> dp(len);
        int ans = abs(arr[0] - target);
        for(int i = len - 1; i >= 0; i--) 
            //In round i, dp[i], dp[i+1]...dp[N-1] is our new sequence of arr[i], arr[i]&arr[i+1],...,arr[i]&...&arr[N-1]
        {
            for(int j = 0; j < 30; j++) if(!((arr[i] >> j) & 1))
                while(!tab[j].empty() && tab[j].back() > i) 
                    //Find elements whose j'th bit need to be set to zero
                {
                    dp[tab[j].back()] -= 1 << j;
                    tab[j].pop_back(); 
                    //After set this element's j'th bit to zero, we need not consider this bit again
                }
            dp[i] = arr[i];

            //Binary search
            int l = i, r = len;
            while(l < r)
            {
                int m = l + (r - l) / 2;
                if(dp[m] > target) l = m + 1;
                else r = m;
            }
            if(l == len) ans = min(ans, abs(target - dp[l - 1]));
            else if(l == i) ans = min(ans, abs(target - dp[l]));
            else ans = min(ans, min(abs(target - dp[l]), abs(target - dp[l - 1])));
        }
        return ans;
    }
};


class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int len = (int)arr.size();
        vector<vector<int> > tab(30);
        for(int i = 0; i < len; i++)
            for(int j = 0; j < 30; j++) if((arr[i] >> j) & 1)
                tab[j].push_back(i);

        vector<int> dp(len + 1); dp[len] = arr[0]; 
        //dummy value to avoid "index out of range"
        int ans = abs(arr[0] - target);
        int l = len - 1;
        for(int i = len - 1; i >= 0; i--)
        {
            for(int j = 0; j < 30; j++) if(!((arr[i] >> j) & 1))
                while(!tab[j].empty() && tab[j].back() > i)
                {
                    dp[tab[j].back()] -= 1 << j;
                    tab[j].pop_back();
                }
            dp[i] = arr[i];

            while(l > i && dp[l] < target) l--; 
            //After this line, we have dp[l] >= target, dp[l + 1] < target,
            //or l == i and all elements in this new sequence is smaller than target
            ans = min(ans, min(abs(target - dp[l]), abs(target - dp[l + 1])));
        }
        return ans;
    }
};