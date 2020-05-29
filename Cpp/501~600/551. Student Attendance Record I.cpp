class Solution {
public:
    bool checkRecord(string s) {
        int L = 0, A = 0, L_cnt = 0;
        for (auto &c : s) {
            switch(c) {
                case 'A': A++; L_cnt = 0; break;
                case 'L': L = max(L, ++L_cnt); break;
                case 'P': L_cnt = 0; break;
            }
        }
        return L < 3 && A < 2;
    }
};