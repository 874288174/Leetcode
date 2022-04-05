class Solution {
public:
    string getWord(const string& expr, int& i) {
        string res;
        while ('a' <= expr[i] && expr[i] <= 'z')
            res += expr[i++];
        return res;
    }

    unordered_set<string> dfs(const string& expr, int& i) {
        unordered_set<string> res, S;
        
        while (i < expr.length() && expr[i] != '}') {
            if (expr[i] == ',') {
                for (auto& i : S) res.insert(move(i));
                ++i;
                S.clear();
            }
            else {
                unordered_set<string> t;
                if (expr[i] == '{')
                    t = dfs(expr, ++i);
                else 
                    t.insert(getWord(expr, i));
                
                if (S.empty()) S = std::move(t);
                else {
                    unordered_set<string> S2;
                    for (auto& i : S) {
                        for (auto& j : t)
                            S2.insert(i + j);
                    }
                    S = std::move(S2);
                }
            }
        }
        
        for (auto& i : S) res.insert(move(i));
        ++i;
        return res;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        auto S = dfs(expression, i);
        vector<string> res(S.begin(), S.end());
        sort(res.begin(), res.end());
        return res;
    }
};