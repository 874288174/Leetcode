class Solution {
public:
    int minimumDistance(string word) {
        vector<int> dp(26);
        //dp[the postiopn of the second finger] = save dist
        int res = 0, n = word.size();
        for (int i = 0; i < n - 1; ++i) {
            int b = word[i] - 'A', c = word[i + 1] - 'A';
            for (int a = 0; a < 26; ++a)
                dp[b] = max(dp[b], dp[a] + d(b, c) - d(a, c));
            res += d(b, c);
        }
        return res - *max_element(dp.begin(), dp.end());
    }

    int d(int a, int b) {
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }
};
