class Solution {
public:
    vector<string> addOperators(string num, int target) {
        if (num.empty()) return {};
        string expr(num.size()*2, '\0');
        this->num = num;
        this->target = target;
        dfs(0, expr, 0, 0, 0); 
        return res;
    }
    
private:
    string num;
    int target;
    vector<string> res;
    
    void dfs(int pos, string &expr, int len, long prev, long cur) {
        if (pos == num.size()) {
            if (cur == target) res.push_back(expr.substr(0, len));
            return;
        }
        
        long n = 0;
        int start = pos;
        int l = len;
        if (start != 0) ++len; // leave the place for operator
        while (pos < num.size()) {
            n = 10*n + num[pos]-'0';
            if (num[start] == '0' && pos > start) break;
            expr[len++] = num[pos++];
            if (start == 0) dfs(pos, expr, len, n, n);
            else {
                expr[l] = '+';;
                dfs(pos, expr, len, n, cur+n);
                expr[l] = '-';
                dfs(pos, expr, len, -n, cur-n);
                expr[l] = '*';
                dfs(pos, expr, len, prev*n, cur-prev+prev*n);
            }
        }
    }
};