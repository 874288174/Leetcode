class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        for (int i = s.length()-1; i > 0; i--) {
            if (s[i] == '+' && s[i-1] == '+') {
                string t = s;
                t[i] = t[i-1] = '-';
                res.push_back(t);
            }
        }
        return res;
    }
};