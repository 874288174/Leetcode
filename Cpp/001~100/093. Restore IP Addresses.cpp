class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string t;
        dfs(0, s , t, 4, res);
        return res;
    }
private:
    void dfs(int cur, string &s, string t, int cnt, vector<string> &res) {
        if (cnt == 1) {
            string a = s.substr(cur);
            if(a.length() > 3 || (a[0] == '0' && a != "0")) return;
            if (stoi(a) < 256)   res.push_back(t + a);
        }
        else for(int k = 1; k <= 3 && cur+k < s.length(); k++) {
            string a = s.substr(cur, k);
            if (k !=3 || stoi(a) < 256)  dfs(cur+k, s, t+a+'.', cnt-1, res);
            if (a[0] == '0') break;
        }
    }
};