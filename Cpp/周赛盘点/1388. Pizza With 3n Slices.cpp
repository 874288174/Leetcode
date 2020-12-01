//解题技巧：环形变线性 掐头去尾
//注意题目每次取都可以取任意一块，即最后所有取的不相邻即可
class Solution {
public:
    int maxSizeSlices(vector<int>& v) {
        int n = v.size() / 3;
        auto l1 = vector<int>(v.begin(), v.end()-1);
        auto l2 = vector<int>(v.begin()+1, v.end());
        return max(linear(l1, n), linear(l2, n));
    }
    
private:
    int linear(vector<int>& v, int n) {
        vector<vector<int>> dp(v.size()+1, vector<int>(n+1));
        //dp[i][j]到第i个吃了j个的最大值
        int res = 0;
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < n+1; ++j) {
                if (i == 1) dp[i][j] = v[0];
                else dp[i][j] = max(dp[i-1][j], dp[i-2][j-1] + v[i-1]);
            }
        }
        return dp.back().back();
    }
};