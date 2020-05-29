class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n = 0, m = 0, cnt_n = 0, cnt_m = 0;
        for (auto &i : nums) {
            if (i == n) cnt_n++;
            else if (i == m) cnt_m++;
            else if(!cnt_n) {n = i; cnt_n = 1;}
            else if(!cnt_m) {m = i; cnt_m = 1;}
            else {cnt_n--;  cnt_m--;}
        }
        cnt_n = cnt_m = 0;
        for (auto &i : nums){
            if(i == n) cnt_n++;
            else if(i == m) cnt_m++;
        }
        if(cnt_n > floor(nums.size()/3) ) res.push_back(n);
        if(cnt_m > floor(nums.size()/3) ) res.push_back(m);
        return res;
    }
};