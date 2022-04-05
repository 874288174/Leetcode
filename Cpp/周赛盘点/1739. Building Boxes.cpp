class Solution {
public:
    using ll = long long;
    
    bool check(int a, int n) {
        ll sum = 0;
        while (a != 0) {
            sum += a;
            int k = ceil(sqrt(2*a+1.0/4) - 1.0/2);
            a -= k;
        }
        return sum >= n;
    }
    
    
    int minimumBoxes(int n) {
        int l = 1, r = n;
        while (l < r) {
            int mid = l + (r-l) / 2;
            if (check(mid, n)) r = mid;
            else l = mid+1;
        }
        return l;
    }
};