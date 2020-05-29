class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int num1 = 0, num2 = 0;
        for(char &c : s) {
            num1 += c == '(';
            if (num1 == 0) num2 += c == ')';
            else num1 -= c == ')';
        }
        vector<string> ret;
        dfs(s, 0, num1, num2, ret);
        return ret;
    }
private:
    bool isValid(string s) {
        int sum = 0;
        for(char &c : s) {
            if (c == '(') ++sum;
            else if (c == ')') --sum;
            if (sum < 0) return false;
        }
        return sum == 0;
    }
    
    void dfs(string &s, int cur, int num1, int num2, vector<string> &ret) {
        if (num1 == 0 && num2 == 0) {
            if (isValid(s))
                ret.push_back(s);
            return;
        } 
        for (int i = cur; i < s.size(); ++i) {
            string tmp = s;
            if (num1 > 0 && tmp[i] == '(') {
                if (i == cur || tmp[i] != tmp[i - 1]) {
                    tmp.erase(i, 1);
                    dfs(tmp, i, num1 - 1, num2, ret);
                }
            }
            if (num2 > 0 && tmp[i] == ')') {
                if (i == cur || tmp[i] != tmp[i - 1]) {
                    tmp.erase(i, 1);
                    dfs(tmp, i, num1, num2 - 1, ret);
                }
            }
        }
    }
};