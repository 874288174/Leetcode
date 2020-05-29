class Solution{
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        int len = s1.length();
        vector<vector<vector<bool>>> dp(len,
                                        vector<vector<bool>>(len,
                                                             vector<bool>(len + 1,
                                                                          false)));
        for (size_t i = 0; i < len; ++i) {
            for (size_t j = 0; j < len; ++j) {
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }

        for (int subLen = 2; subLen <= len; ++subLen) {
            int len0 = len - subLen;
            for (int i = 0; i <= len0; ++i) {
                for (int j = 0; j <= len0; ++j) {
                    for (int k = 0; k < subLen-1 && !dp[i][j][subLen]; ++k){
                        int len1 = k + 1, len2 = subLen - len1;
                        dp[i][j][subLen] =  (dp[i][j][len1] && dp[i + len1][j + len1][len2]) 
                                         || (dp[i][j + len2][len1] && dp[i + len1][j][len2]);
                    }
                }
            }
        }
        return dp[0][0][len];
    }
};






////////////////////////////////////////////////////////

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
            
        int len = s1.length();
        int cnt[26] = {0};
        for(int i = 0; i < len; i++) {
            cnt[s1[i]-'a']++;
            cnt[s2[i]-'a']--;
        }
        
        for (int i : cnt) {
            if (i != 0)
                return false;
        }
        
        for(int i = 1; i < len; i++) {
            if (isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if (isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i)))
                return true;
        }
        return false;
    }
}