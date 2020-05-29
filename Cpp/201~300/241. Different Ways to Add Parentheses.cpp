class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        return computeWithDP(0, input.size()-1, input);
    }

private:
    using pii = pair<int, int>;
    map<pii, vector<int>> dp;
    
    vector<int> computeWithDP(int i, int j, const string &input) {
        if (dp.count({i, j})) return dp[{i, j}];
        vector<int> result;
        for (int k = i; k <= j; k++) {
            char c = input[k];
            if (ispunct(c)) {
                auto res1 = computeWithDP(i, k-1, input);
                auto res2 = computeWithDP(k+1, j, input);
                for (auto n1 : res1) {
                    for (auto n2 : res2) {
                        result.push_back(c == '+' ? n1+n2
                                                        : c == '-' ? n1-n2 : n1*n2);
                    }
                }
            }
        }
        if (result.empty()) result.push_back(stoi(input.substr(i, j-i+1)));
        return dp[{i, j}] = result;
    }
};
