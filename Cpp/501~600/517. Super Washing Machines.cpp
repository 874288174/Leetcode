class Solution {
public:
    using ll = long long;
    int findMinMoves(vector<int>& v) {
        int n = v.size();
        ll sum = accumulate(v.begin(), v.end(), 0ll);
        if (sum % n != 0) return -1;
        int avg = sum/n;
        
        int currSum = 0, maxSum = 0, res = 0;
        for (auto m : v) {
            m -= avg;
            currSum += m;
            maxSum = max(maxSum, abs(currSum));
            res = max(res, max(maxSum, m));
        }
        return res;
    }
};