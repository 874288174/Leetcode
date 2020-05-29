class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int t = m+n-1, p = m-1, q = n-1;
        while (p >= 0 || q >= 0) {
            if (p >= 0 && q >= 0) {
               if (nums1[p] > nums2[q]) nums1[t--] = nums1[p--];
               else nums1[t--] = nums2[q--];
            }
            else if (q >= 0) {
                while (q >= 0) nums1[t--] = nums2[q--];
            }
            else break;
        }
    }
}