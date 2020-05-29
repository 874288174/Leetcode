class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, l = 0, r = height.size()-1;
        while (l < r) {
            int MIN = min(height[l], height[r]);
            if (MIN == height[l]) {
                ++l;
                while (l < r && height[l] < MIN) res += MIN-height[l++];
            } else {
                --r;
                while (l < r && height[r] < MIN) res += MIN-height[r--];
            }
        }
        return res;
    }
};
