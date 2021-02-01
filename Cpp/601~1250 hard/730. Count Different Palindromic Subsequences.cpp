/*
if s[i]!=s[j] dp(i,j)=dp(i,j-1)+dp(i+1,j)-dp(i+1,j-1)
else 定义left(i)表示第一个和s(i)相同的下标 right(j)表示第一个和s(j)相同的下标有：
if left(i)>right(j) 即i和j之间不存在和s(i)相同的元素 有 dp(i,j)=dp(i+1,j-1)*2+2 (+2是加单个s（i）和一对s（i）)
if left(i)=right(j) 即i和j之间有且只有一个元素和s(i)相同 有 dp(i,j)=dp(i+1,j-1)*2+1 (+1是加一对s(i) 单个s（i）已经有了)
if left(i)<right(j) 即i和j之间有一个区间也是s(i)元素包裹的 有 dp(i,j)=dp(i+1,j-1)*2-dp(left(i)+1,right(j)-1) (left+1和right-1之间的回文串不需要再叠加)
*/
class Solution {
public:
    int countPalindromicSubsequences(string s) {
        const int n = s.length(), mod = 1e9+7;
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) dp[i][i] = 1;

        for (int i = n-1; i >= 0; i--) {
            for (int j = i+1; j < n; j++) {
                if (s[i] == s[j]) {
                    int left = i+1,right = j-1;
                    while (left <= right && s[left] != s[i]) ++left;
                    while (right >= left && s[right] != s[j]) --right;
                    if (left > right) dp[i][j] = dp[i+1][j-1]*2 + 2;
                    else if (left == right) dp[i][j] = dp[i+1][j-1]*2 + 1;
                    else dp[i][j] = dp[i+1][j-1]*2 - dp[left+1][right-1];
                }
                else {
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
                }
                dp[i][j] %= mod;
            }
        }
        return static_cast<int> ((dp[0][n-1]+mod) % mod);
    }
};