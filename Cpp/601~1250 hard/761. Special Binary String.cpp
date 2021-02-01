class Solution {
public:
    string makeLargestSpecial(string S) {
        vector<string> v;
        for (int j = 0, i = 0, cnt = 0; j < S.size(); ++j) {
            S[j] == '1' ? ++cnt : --cnt;
            if (cnt < 0) return S;
            if (cnt == 0) {
                v.push_back('1' + makeLargestSpecial(S.substr(i + 1, j - i - 1)) + '0');
                i = j + 1;
            }
        }
        sort(v.begin(), v.end(), greater<>());
        string res;
        for (auto &s : v) res += s;
        return res;
    }
};