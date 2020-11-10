class Solution {
public:
    int minDays(vector<int>& v, int m, int k) {
        int n = v.size();
        if (n < m*k) return -1;
        int lo = *min_element(v.begin(), v.end());
        int hi = *max_element(v.begin(), v.end());
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            if (check(v, m, k, mid)) hi = mid;
            else lo = mid + 1;
        }
        return hi;
    }
    
    bool check(vector<int>& v, int m, int k, int day) {
        int sum = 0;
        for (int i : v) {
            if (i <= day) {
                if (++sum == k) {
                    if (--m == 0) return true;
                    sum = 0;
                }
            }
            else sum = 0;
                
        }
        return false;
    }
};