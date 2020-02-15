class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;
        for (auto c : s) {
            if (stk.empty() || stk.top().first != c) {
                stk.push(make_pair(c, 1));
            }
            else if (++stk.top().second == k) {
                stk.pop();
            }
        }
        
        string res;
        while (!stk.empty()) {
            auto t = stk.top();
            stk.pop();
            res += string(t.second, t.first);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};