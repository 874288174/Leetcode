class NumArray {
public:
    NumArray(vector<int> nums) { 
       partial_sum(nums.begin(), nums.end(), back_inserter(sum));
    }
    
    int sumRange(int i, int j) {
        return sum[j+1]-sum[i];
    }
private:
    vector<int> sum{0};
};
