class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, n = height.size();
        vector<int> L_MAX(n, 0);
        for (int i = 0; i < n; i++){
           if(!i) L_MAX[i] = height[i];
           else   L_MAX[i] = max(height[i], L_MAX[i-1]);
        }
        int R_MAX = height[n-1]; 
        for (int i = n-2; i >= 0; i--){
            if (R_MAX < height[i]){
               R_MAX = height[i];
               continue;
            }
            else res += min(R_MAX-height[i], L_MAX[i]-height[i]);
        }
        return res;
    }
};




/////////////////////////////////////////////////////////////////////////////
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
