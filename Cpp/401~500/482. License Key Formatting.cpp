class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res;
        int cnt = 0;
        for (auto it = S.rbegin(); it != S.rend(); it++)  if (*it != '-') {
            if (cnt++ % K == 0 && cnt != 1) res += '-';
            res += toupper(*it);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};