class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int a[26] = {0};
        for(auto &i : s)  a[i-'a']++;
        for(auto &i : t){ 
            if(--a[i-'a'] < 0)
                return false;
        }
        return true;
    }
};