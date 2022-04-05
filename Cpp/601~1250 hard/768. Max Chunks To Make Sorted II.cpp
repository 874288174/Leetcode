//O(nlogn)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        auto sort_arr(arr);
        sort(sort_arr.begin(), sort_arr.end());
        int n = arr.size(), res = 0, nonzero = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            ++cnt[arr[i]];
            if (cnt[arr[i]] == 0) --nonzero;
            else if (cnt[arr[i]] == 1) ++nonzero;
            --cnt[sort_arr[i]];
            if (cnt[sort_arr[i]] == 0) --nonzero;
            else if (cnt[sort_arr[i]] == -1) ++nonzero;
                
            if (nonzero == 0) ++res;
        }
        return res;
    }
};



//O(n)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stk;
        for (auto &x : arr) {
            if (stk.empty() || x >= stk.top()) stk.push(x);
            else {
                auto top = stk.top();
                s.pop();
                while (!stk.empty() && x < stk.top()) {
                    stk.pop();
                }
                stk.push(top);
            }
        }
        return stk.size();
    }
};





//O(nlogn)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        auto sort_arr(arr);
        sort(sort_arr.begin(), sort_arr.end());
        int n = arr.size(), res = 0;
        long long sum0 = 0, sum1 = 0;
        for (int i = 0; i < n; ++i) {
            sum0 += arr[i];
            sum1 += sort_arr[i];
            if (sum0 == sum1) ++res;
        }
        return res;
    }
};