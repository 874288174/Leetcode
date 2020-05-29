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