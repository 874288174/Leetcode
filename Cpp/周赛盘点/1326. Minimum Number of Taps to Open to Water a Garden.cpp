class Solution {
public:
    int minTaps(int n, vector<int>& nums) {
        vector<int> maxRight(n+1);
        for (int i = 0; i <= n; i++) {
            int L = max(0, i-nums[i]);
            int R = min(n, i+nums[i]);
            maxRight[L] = max(maxRight[L], R);
        }   

        int cnt = 0, cur_right_most = 0;
        
        for(int i = 0; i < n && cur_right_most != n;){
            if (i > cur_right_most){
               return -1;
            }
            ++cnt;
            int far = cur_right_most;
            while (i <= cur_right_most) {
                far = max(far, maxRight[i++]);
            }
            cur_right_most = far;
        }
        return cnt; 
    }
};