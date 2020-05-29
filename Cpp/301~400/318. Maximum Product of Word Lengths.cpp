class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> mask(words.size());
        int res = 0;
        for (int i=0; i < words.size(); ++i) {
            for (char c : words[i])
                mask[i] |= 1 << (c - 'a');
            for (int j = 0; j < i; ++j) if (!(mask[i] & mask[j])) {
                res = max(res, int(words[i].size()*words[j].size()));
            }
        }
        return res;
    }
};

//////////////////////////////////////////////////////////
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> maxlen;
        for (string word : words) {
            int mask = 0;
            for (char c : word)  mask |= 1 << (c - 'a');
            maxlen[mask] = max(maxlen[mask], (int) word.size());
        }
        int res = 0;
        for (auto a : maxlen) {
            for (auto b : maxlen)
               if (!(a.first & b.first))
                   res = max(res, a.second * b.second);           
        }
        return res
    }
};
