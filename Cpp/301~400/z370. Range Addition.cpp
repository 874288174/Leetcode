class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int> > updates){
        vector<int> res(length, 0);
        for (auto &tuple : updates) {
            int start = tuple[0], end = tuple[1], val = tuple[2];
            res[start] += val;
            if (end < length - 1) res[end + 1] -= val;
        }
        partial_sum(res.begin(), res.end(), res.begin());
        return res;
    }
};