class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        if(s.length() != t.length()) return false;
        vector<int> a(256,-1), b(256,-1);
        for (int i = 0; i < n; i++) {
            if(a[s[i]] != b[t[i]] ) return false;
            if(a[s[i]] == -1) a[s[i]] = b[t[i]] = i; 
        }
        return true;
    }
};