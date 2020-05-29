class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = nums1.size(), n2 = nums2.size();
        int i1 = 0, i2 = 0;
        vector<int> res;
        while (i1 < n1 && i2 < n2){
            if (nums1[i1] == nums2[i2]) {
                res.push_back(nums1[i1]);
                i1++; i2++;
                while (i1 < n1 && nums1[i1] == nums1[i1-1]) i1++;
                while (i2 < n2 && nums2[i2] == nums2[i2-1]) i2++;
            }
            else if(nums1[i1] > nums2[i2])  {
                i2++;
                while (i2 < n2 && nums2[i2] == nums2[i2-1]) i2++;
            }
            else {
                i1++;
                while (i1 < n1 && nums1[i1] == nums1[i1-1]) i1++;
            }
        }
        return res;
    }
};


/*
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, bool> m;
        for (auto i : nums1)  m[i] = true;
        for (auto i : nums2) if (m[i]){
            res.push_back(i);
            m[i] = false;
        }  
        return res;
    }
};
*/