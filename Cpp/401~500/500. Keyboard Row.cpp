class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> vect{1,2,2,1,0,1,1,1,0,1,1,1,2,2,0,0,0,0,1,0,0,2,0,2,0,2};
        vector<string> res;
        for (auto &s : words) {
            bool ok = true;
            int r = vect[tolower(s[0])-'a'];
            for (auto c : s) {
                if (vect[tolower(c)-'a'] != r) {
                    ok = false;
                    break;
                }
            }
            if (ok) res.push_back(s); 
        }
        return res;
    }
};