class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = -1, time = 0;
        for(auto &i : nums) {
            i == res ? time++ : time--;
            if (time <= 0) {
               res = i; time = 1;
            }
        }
        return res;
    }
};