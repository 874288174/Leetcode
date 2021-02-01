class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> mp;
        for (const auto &s : words) {
            int mask = 0;
            for (const auto &c : s) {
                mask |= 1 << (c - 'a');
            }
            ++mp[mask];
        }

        vector<int> res;
        for (const auto &s : puzzles) {
            int mask = 0, cnt = 0, firstLetter = 1 << (s[0]-'a');
            for (const auto &c : s) {
                mask |= 1 << (c - 'a');
            }
            for (int j = mask; j != 0; j = (j-1)&mask) {
                if ((firstLetter & j) && mp.count(j))
                    cnt += mp[j];
            }
            res.push_back(cnt);
        }
        return res;
    }
};
