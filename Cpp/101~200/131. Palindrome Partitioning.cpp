class Solution {
public:
    vector<vector<string>> partition(string s) {
        const int n = s.size();
        bool d[n][n];
        fill_n(&d[0][0], n*n, false);
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                d[i][j] = (s[i] == s[j] && (j - i < 2 || d[i+1][j-1]) );
            }
        }
        vector<vector<string>> sub_palindrome[n];
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (d[i][j]) {
                    string p = s.substr(i, j-i+1);
                    if (j+1 < n) {
                        for (auto v : sub_palindrome[j+1]) {
                            v.insert(v.begin(), p);
                            sub_palindrome[i].push_back(v);
                        }
                    }
                    else sub_palindrome[i].push_back(vector<string>{p});
                }
            }
        }
        return sub_palindrome[0];
    }
};      
        
/*
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> v;
        dfs(0, s, v, res);
        return res;
    }
    
private:
    void dfs(int i, string &s, vector<string> &v, vector<vector<string>> &res) {
        if (i == s.length()) res.push_back(v);
        else for (int j = i+1; j <= s.length(); j++) {
            string x = s.substr(i, j-i);
            if (is_palindrome(x)) { 
                v.push_back(x);
                dfs(j, s, v, res);
                v.pop_back();
            }   
        }
    }
    
    bool is_palindrome(string &s){
        int l = 0, r = s.length()-1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};
*/