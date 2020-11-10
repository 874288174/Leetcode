class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.length();
        vector<int> res(n+1);
        for (int i = 0; i < n+1; ++i) res[i] = i + 1;
        int i = 0;
        while (i < n) {
            if (s[i] == 'I') {i++; continue;}
            int j = i;
            while (i < n && s[i] == 'D') ++i;
            reverse(res.begin() + j, res.begin() + i + 1);
        }
        return res;
    }
};