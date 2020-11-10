class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 7) return false;

        vector<int> preS;
        partial_sum(nums.begin(), nums.end(), back_inserter(preS));
    
        for (int j = 3; j < n - 3; ++j) {
            unordered_set<int> st;

            for (int i = 1; i < j-1; ++i) {
                int sum1 = preS[i-1];
                int sum2 = preS[j-1] - preS[i];
                if (sum1 == sum2) st.insert(sum1);
            }
            
            for (int k = j+2; k < n-1; ++k) {
                int sum3 = preS[k-1] - preS[j];
                int sum4 = preS[n-1] - preS[k];
                if (sum3 == sum4 && st.count(sum3)) return true;
            }
        }
        return false;
    }
};