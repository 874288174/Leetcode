class Solution {
public:
    string parseTernary(string s){
        stack<string> stk;
        stk.push("");
        for(int i = s.size()-1; i >= 0; i--) {
            if (s[i] == '?'){
                auto a = stk.top();  stk.pop();
                auto b = stk.top();  stk.pop();
                stk.push(s[--i] == 'T' ? a : b);
            }
            else if (s[i] == ':') stk.push("");
            else {
                auto t = stk.top();
                stk.pop();
                stk.push(s[i] + t);
            }
        }
        return stk.top();
    }
};