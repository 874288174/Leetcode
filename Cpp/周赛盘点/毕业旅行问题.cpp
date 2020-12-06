#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> nums(n,vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> nums[i][j];
    }
    int maxstate = 1 << n;
    
    //dp[i][j] 标识从0开始，经过 i 所表示的状态城市，到达j需要的最小花销
    //因为是环 所以从哪开始都一样！
    vector<vector<int>> dp(maxstate, vector<int>(n, INT_MAX));
    dp[1][0] = 0;
    for (int i = 1; i < maxstate; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] != INT_MAX) {
                for (int k = 0; k < n; k++) {
                    if ((i & (1<<k)) == 0) {
                        int next = i | (1<<k);
                        dp[next][k] = min(dp[next][k], dp[i][j]+nums[j][k]);
                    }
                }
            }
        }
    }
    int res = INT_MAX;
    for(int i = 1; i < n; i++) {
        if(dp[maxstate-1][i] != INT_MAX) {
            res = min(res, dp[maxstate-1][i] + nums[i][0]);
        }
    }
    cout << res << endl;
    return 0;
}