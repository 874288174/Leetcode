class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<string> dp(target + 1, "NAN");
        dp[0] = "";

        auto largeThan = [](string& s1, string& s2) {
            if (s1.size() > s2.size()) return true;
            else if (s1.size() < s2.size()) return false;
            else return s1 > s2;
        };

        for (int i = 1; i <= cost.size(); ++i) {
            for (int j = cost[i - 1]; j <= target; ++j) {
                if (dp[j-cost[i-1]] != "NAN") {
                    string newVal = to_string(i) + dp[j-cost[i-1]];
                    if (dp[j] == "NAN" || largeThan(newVal, dp[j])) {
                        dp[j] = newVal;
                    }
                }
            }
        }

        return dp[target] == "NAN" ? "0" : dp[target];
    }
};