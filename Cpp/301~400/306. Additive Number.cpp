class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        for (int i = 1; i <= n/2; i++) {
            for (int j = i+1; j < n; j++) {
                if (dfs(num.substr(0, i), num.substr(i, j-i), j, num, 2)) 
                    return true;
            }
        }
        return false;
    }
private:
    bool dfs(string x, string y, int start, string &num, int cnt) {
        if (x[0] == '0' && x != "0") return false;
        if (y[0] == '0' && y != "0") return false;
        if (start == num.length() && cnt > 2) return true;
        string s = add(x, y); 
        if (s != num.substr(start, s.length())) return false;
        return dfs(y, s, start+s.length(), num, cnt+1);
    }
    
    string add(string x, string y) {
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());
        string ret;
        int c = 0, p = 0, q = 0, n = x.length(), m = y.length();
        while (p < n || q < m) {
            c += (p < n ? x[p++] -'0' : 0 ) + (q < m ? y[q++] -'0' : 0 );
            ret += c % 10 + '0';
            c /= 10;
        }
        if (c) ret += '1';
        reverse(ret.begin(), ret.end());
        return ret;
    }
};