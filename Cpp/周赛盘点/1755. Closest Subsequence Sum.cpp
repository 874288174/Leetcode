class Solution {
public:
    void get_sum(vector<int> nums, vector<int> &sum) {
        int n = nums.size();
        for (int i = 1; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) == 0) continue;
                sum[i] = sum[i-(1<<j)] + nums[j];
                break;
            }
        }
    }
    
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size(), half = n / 2;
        int ls = half, rs = n - half;
        
        vector<int> lsum(1 << ls, 0);
        vector<int> rsum(1 << rs, 0);
     
        get_sum(vector<int> (nums.begin(), nums.begin()+half), lsum);
        get_sum(vector<int> (nums.begin()+half, nums.end()), rsum);

        sort(lsum.begin(), lsum.end());
        sort(rsum.begin(), rsum.end());
        
        int ret = INT_MAX;
        for (int x: lsum) ret = min(ret, abs(goal - x));
        for (int x: rsum) ret = min(ret, abs(goal - x));
        
        int i = 0, j = rsum.size() - 1;
        while (i < lsum.size() && j >= 0) {
            int s = lsum[i] + rsum[j];
            ret = min(ret, abs(goal - s));
            if (s > goal) j--;
            else i++;
        }
        return ret;
    }
};