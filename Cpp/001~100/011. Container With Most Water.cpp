class Solution {
public:
    int maxArea(vector<int> &height) {
        int MAX = -1, L = 0, R = height.size()-1;
        while(L < R) {
            MAX = max(MAX, (R - L)*min( height[L], height[R]));
            if (height[L] > height[R]) R--;
            else L++;
        }
        return MAX;
    }
};