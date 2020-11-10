class Solution {
public:
    string parseTernary(string s){
        stack<char> stk;
        for(int i = s.size()-1; i >= 0; i--) {
            if (s[i] == '?'){
                auto a = stk.top();  stk.pop();
                auto b = stk.top();  stk.pop();
                stk.push(s[--i] == 'T' ? a : b);
            }
            else if (s[i] == ':') continue;
            else stk.push(s[i]);
        }
        return string(1, stk.top());
    }
};