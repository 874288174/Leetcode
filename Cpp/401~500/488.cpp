class Solution {
public:
    int res = INT_MAX;
    
    int findMinStep(string board, string hand) {
        vector<int> cnts(26);
        for(const auto& ch : hand) ++cnts[ch - 'A'];
        dfs(board, cnts, 0);
        return res == INT_MAX ? -1 : res;
    }

private:
    void dfs(const string& s, vector<int>& cnts, int step) {
        if (step >= res) return;
        if (s.empty()) {
            res = min(res, step);
            return;
        }
        int n = s.size();
        for (int i = 0, j = i; i < n; ++i) {
            if (j + 1 < n && s[j + 1] == s[i]) ++j;
            if (i == j && cnts[s[i] - 'A'] > 1) {
                cnts[s[i] - 'A'] -= 2;
                string tmp = s;
                string t = string(2, s[i]);
                tmp.insert(tmp.begin() + i, t.begin(), t.end());
                dfs(eliminate(tmp), cnts, step + 2);
                cnts[s[i] - 'A'] += 2;
            } else if (j > i) {
                if (cnts[s[i] - 'A'] > 0) {
                    --cnts[s[i] - 'A'];
                    string temp = s;
                    temp.insert(temp.begin() + i, s[i]);
                    dfs(eliminate(temp), cnts, step + 1);
                    ++cnts[s[i] - 'A'];
                }
                for (char ch : {'R', 'Y', 'B', 'G', 'W'}) {
                    if (ch == s[i] || !cnts[ch - 'A']) continue;
                    --cnts[ch - 'A'];
                    string tmp = s;
                    tmp.insert(tmp.begin() + j, ch);
                    dfs(eliminate(tmp), cnts, step + 1);
                    ++cnts[ch - 'A'];
                }
            }
        }
    }

     string eliminate(string &s) {
        string res;
        vector<pair<char, int>> stk;
        for (auto c : s) {
            while (!stk.empty() && stk.back().first != c && stk.back().second > 2) stk.pop_back();
            if (stk.empty() || stk.back().first != c)
                stk.emplace_back(c, 1);
            else stk.back().second++;
        }
        while (!stk.empty() && stk.back().second > 2) stk.pop_back();
        for (auto [c, t] : stk) res += string(t, c);
        return res;
    }
};