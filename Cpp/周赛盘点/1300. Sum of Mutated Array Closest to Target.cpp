class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> v{0};
        partial_sum(arr.begin(), arr.end(), back_inserter(v));
        int sum = v.back(), l = 0, r = arr.back();
        int sub = INT_MAX, res = INT_MAX;
        while (l <= r) {
            int mid = l + (r-l)/2;
            int pos = lower_bound(arr.begin(), arr.end(), mid) - arr.begin();
            int cur_sum = v[pos] + (n-pos)*mid;
            if (abs(target-cur_sum) < sub || abs(target-cur_sum) == sub && mid < res) {
                res = mid;
                sub = abs(target-cur_sum);
            }
            if (cur_sum == target) return mid;
            else if (cur_sum > target) r = mid-1;
            else l = mid+1;
        }
        return res;
    }
};



class Solution {
public:
    int findBestValue(vector<int>& A, int target) {
        sort(A.begin(), A.end());
        int n = A.size(), i = 0;
        while (i < n && target > A[i] * (n - i))
            target -= A[i++];
        return i == n ? A[n - 1] : int(round((target - 0.0001) / (n - i)));
    }
};