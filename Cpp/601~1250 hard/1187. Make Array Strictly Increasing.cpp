class Solution {
public:
    //dp[i][k]表示当前进行到第i个数，且最后一个数不超过k时最少需要的操作次数
    const static int INF = 0x3f3f3f3f;
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2) {
        set<int> st(arr1.begin(), arr1.end());
        for (int i : arr2) st.insert(i); 

        // 建立索引关系，离散化
        unordered_map<int, int> mp;
        int idx = 0;
        for (int i : st) mp[i] = ++idx;
        
        for (int &i : arr1) i = mp[i];
        for (int &i : arr2) i = mp[i];

        unordered_set<int> b(arr2.begin(), arr2.end());
        int n = arr1.size(), m = st.size();
        vector<int> dp(m + 1, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = m; j >= 0; --j) {
                dp[j] = INF;
                if (j == arr1[i])
                    dp[j] = min(dp[j], dp[j-1]);
                else if (b.find(j) != b.end())
                    dp[j] = min(dp[j], dp[j-1] + 1);
            }
            for (int j = 1; j <= m; ++j) 
                dp[j] = min(dp[j], dp[j-1]);
        }
        return dp[m] == INF ? -1 : dp[m];
    }
};