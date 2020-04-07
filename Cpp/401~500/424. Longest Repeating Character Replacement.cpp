class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), ret = 0;
        vector<int> cnt(26, 0);
        int start = 0, end = 0, localMaxFreq = 0; 
        for(; end < n; end++) {
            localMaxFreq = max(localMaxFreq, ++cnt[s[end]-'A']);
            if ((end-start+1) - localMaxFreq > k) {
                --cnt[s[start++]-'A'];
                localMaxFreq = *max_element(cnt.begin(), cnt.end());
            }
            else ret = max(ret, end-start+1);
        }
        return ret;
    }
};
