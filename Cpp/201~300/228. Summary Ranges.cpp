class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) return res;
        nums.push_back(nums.back());
        long low, st, i = 0; 
        string s;
        while (i < nums.size()) {
            if (s.empty()) {
                s = to_string(st = low = nums[i++]);
            }
            else if (nums[i] != ++low) {
               if (low-1 != st) res.push_back(s + "->" + to_string(low-1));
               else res.push_back(s);
               s.clear();
            }
            else i++;
        }
        return res;
    }
};