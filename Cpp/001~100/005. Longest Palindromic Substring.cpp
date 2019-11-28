class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.length();
        if(!n) return s;
        bool dp[n][n] = {false};
        int start = 0, len = 1;
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
            if (i+1 < n && s[i] == s[i+1]) {
                dp[i][i+1] = true;
                len = 2;
                start = i;
            }
        }
    
        for (int k = 2; k < n; k++) {
            for (int i = 0; i < n-k; i++) {
                bool Flag = false;
                if (s[i] == s[k+i] && dp[i+1][i+k-1]) 
                    dp[i][i+k] = Flag = true;
                if (Flag) {
                   start = i; len = k+1;
                }
            }
       } 
       return s.substr(start, len);  
   }
};




//////////////////////////////////////////ÂíÀ­³µ////////////////////////
class Solution {
public:
    string longestPalindrome(string s) {
        string T = preProcess(s);
        const int n = T.length();
        int P[n];
        int C = 0, R = 0;
        for (int i = 1; i < n - 1; i++) {
            int i_mirror = 2 * C - i;
            P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]])  P[i]++;
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }
        int max_len = 0, center_index = 0;
        for (int i = 1; i < n - 1; i++) {
            if (P[i] > max_len) {
                max_len = P[i];
                center_index = i;
            }
        }
        return s.substr((center_index - 1 - max_len) / 2, max_len);
    }
private:
    string preProcess(string &s) {
        int n = s.length();
        if (n == 0) return "^$";
        string ret = "^";
        for (int i = 0; i < n; i++) ret += "#" + s.substr(i, 1);
        return ret + "#$";
    }
}