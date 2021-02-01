class Solution {
public:
    using mp = map<string, int>;
    stack<mp> stk;
    mp cur;
    string pre, res;
    bool flag = false;
    
    string countOfAtoms(string formula) {
        stringstream ss(formula);
        char c;
        while (ss >> c) {
            if (c == '(') {
                mp tmp;
                swap(tmp, cur);
                stk.push(std::move(tmp));
            }
            else if (c == ')') flag = true;
            else if (isdigit(c)) {
                int cnt = c - '0';
                while (isdigit(ss.peek())) {
                    ss >> c;
                    cnt = cnt*10 + c-'0';
                }
                if (flag) {
                    for (auto &[s, n] : cur) n *= cnt;
                    for (auto &[s, n] : stk.top()) cur[s] += n;
                    stk.pop();
                    flag = false;
                }
                else cur[pre] += cnt-1;
            }
            else {
                string t = string(1, c);
                while (islower(ss.peek())) {
                    ss >> c;
                    t += c;
                }
                ++cur[pre = t];
            }
        }
        while (!stk.empty()) {
            for (auto &[s, n] : stk.top()) cur[s] += n;
            stk.pop();
        }
        for (auto &[s, n] : cur) {
            res += s + (n == 1 ? "" : to_string(n));
        }
        return res;
    }
};