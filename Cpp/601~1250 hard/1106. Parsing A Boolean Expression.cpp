class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char> stk;
        for (const auto &c : s) {
            if (c == ')') {
                auto hasT = false, hasF = false;
                while (stk.top() == 't' || stk.top() == 'f') {
                    hasT |= stk.top() == 't';
                    hasF |= stk.top() == 'f';
                    stk.pop();
                }
                auto op = stk.top();
                stk.pop();
                stk.push(op == '!' ? hasF ? 't' : 'f' : op == '&' ? !hasF ? 't' : 'f' : hasT ? 't' : 'f');
            }
            else if (c != ',' && c != '(') stk.push(c);
        }
        return stk.top() == 't';
    }
};