class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> v(n, 0);
        v[0] = arr[0];
        for (int i = 1; i < n; ++i) v[i] += v[i-1] + arr[i];
        int sum = v.back(), l = min(arr[0], target/n), r = arr.back();
        int sub = INT_MAX, res = INT_MAX;
        while (l <= r) {
            int mid = l + (r-l)/2;
            int pos = lower_bound(arr.begin(), arr.end(), mid) - arr.begin();
            int cur_sum = (pos == 0 ? 0 : v[pos-1]) + (n-pos)*mid;
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