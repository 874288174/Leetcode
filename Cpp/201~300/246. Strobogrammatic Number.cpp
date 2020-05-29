class Solution {
public:
    bool isStrobogrammatic(string s) {
        unordered_map<char, char> m{{'6','9'}, {'9','6'}, {'8','8'}, {'1','1'}, {'0','0'}};
        int n = s.size();
        for (int i = 0; i <= n/2; i++) {
            if (m[s[i]] != s[n-1-i]) {
                return false;
            } 
        }
        return true;
    }
};