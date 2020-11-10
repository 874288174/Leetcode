class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        for (int i = (1 << word.length()) - 1; i >= 0; --i)
            res.emplace_back(f(word, i));
        return res;
    }

   string f(const string &word, int x) {
        string s;
        int cnt = 0, n = word.length();
        for (int i = 0; i < n; ++i, x >>= 1) {
            if ((x & 1) == 0) {
                if (cnt != 0) {
                    s += to_string(cnt);
                    cnt = 0;
                }
                s += word[i];
            }
            else ++cnt;
        }
        if (cnt != 0) s += to_string(cnt);
        return s;
    }
};