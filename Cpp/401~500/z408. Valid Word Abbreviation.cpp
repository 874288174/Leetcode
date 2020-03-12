class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        if (abbr.empty()) return false;
        size_t i = 0, n = abbr.size(), j = 0, m = word.size();
        vector<string> v;
        string num = "";
        while (i < n) {
            if (isdigit(abbr[i])) {
                if (num.empty() && abbr[i] == '0') return false;
                num += abbr[i++];
            }
            else {
                if (!num.empty()) v.push_back(num);
                num = "";
                v.push_back(string(1, abbr[i++]));
            }
        }
        if (!num.empty()) v.push_back(num);
        for (auto &s : v) {
            if (j >= m) return false;
            if (isalpha(s[0])) {
                if (s[0] != word[j++]) return false;
            }
            else j += stoi(s);
        }
        return j == m;
    }
};