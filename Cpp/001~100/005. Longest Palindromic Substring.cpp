class Solution {
public:
    string longestPalindrome(string s) {
        string T = preProcess(s);
        const int n = T.length();
        vector<int> P(n);
        int C = 0, R = 0;
        for (int i = 1; i < n-1; i++) {
            int i_mirror = 2 * C - i;
            P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]])  P[i]++;
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }
        auto pos = max_element(P.begin(), P.end());
        int len = *pos;
        
        return s.substr((pos-P.begin() - 1 - len) / 2, len);
    }
private:
    string preProcess(string &s) {
        if (s.empty()) return "^$";
        string ret = "^";
        for (auto c : s) ret += string(1, '#') + c;
        return ret + "#$";
    }
};