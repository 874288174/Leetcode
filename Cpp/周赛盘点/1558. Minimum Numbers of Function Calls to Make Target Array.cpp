class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), res = 0, B = 0;
        for (auto i : nums) {
            int a = 0, b = 0;
            while (i) {
                if (i % 2 == 0) i /= 2, ++b;
                else --i, ++a;
            }
            res += a;
            B = max(B, b);
        }
        return res + B;
    }
};