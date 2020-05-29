class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, long lower, int upper) {
        vector<string> res;
        for (long i : nums) {
            if (i < lower) continue;
            else if (i == lower) lower++;
            else {
                res.push_back(to_string(lower) + (i-lower == 1 ? "" : ("->" + to_string(i-1))));
                lower = i+1;
            }
        }
        if (lower - upper != 1) {
            res.push_back(to_string(lower) + (upper == lower ? "" : ("->" + to_string(upper))));
        }
        return res;
    }
};