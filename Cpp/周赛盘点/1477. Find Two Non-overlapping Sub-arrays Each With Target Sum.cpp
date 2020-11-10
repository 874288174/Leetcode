class Solution {
public:
    unordered_map<int,int> mp{{0, 0}};  
    
    int minSumOfLengths(vector<int>& arr, int tar) {
        int n = arr.size(), cursum = 0;
        int k = 2;
        vector<vector<int>> dp(n+1, vector<int> (k+1, 1e9));

        for (int i = 0; i < dp.size(); i++) dp[i][0] = 0;  
        
        for (int i = 1; i <= n; i++) {
            int d = -1;  
            cursum += arr[i-1];
            mp[cursum] = i;
            if (mp.count(cursum - tar)) d = mp[cursum-tar];
            
            for (int j = 1; j <= k; j++) {  
                dp[i][j] = min(dp[i][j], dp[i-1][j]);  
                if (d != -1) {
                    dp[i][j] = min(dp[i][j], dp[d][j-1] + i - d);
                }
            }
        }
        if (dp[n][k] >= 1e9) return -1;   
        return dp[n][k];   
    }
};
