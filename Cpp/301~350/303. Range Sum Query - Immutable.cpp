class NumArray {
public:
    NumArray(vector<int> nums) { 
        int n = nums.size();
        sum.resize(n+1);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j+1]-sum[i];
    }
private:
    vector<int> sum;
};