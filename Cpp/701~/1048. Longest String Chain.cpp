class Solution {
public:
    int longestStrChain(vector<string>& words) {
        auto cmp = [](const string &s1, const string &s2) {
            return s1.length() < s2.length();
        };
        sort(words.begin(), words.end(), cmp);
        unordered_map<string, int> dp;
        int res = 0;
        for (const string &w : words) {
            for (int i = 0; i < w.length(); i++)
                dp[w] = max(dp[w], dp[w.substr(0, i) + w.substr(i + 1)] + 1);
            res = max(res, dp[w]);
        }
        return res;
    }
};