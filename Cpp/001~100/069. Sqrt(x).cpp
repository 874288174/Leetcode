class Solution {
public:
    int mySqrt(int x) {
        int low = 0,  high = x, mid;
        if(x < 2) return x; 
        while (low < high) {
            mid = low + (high-low)/2;
            if(x/mid >= mid) low = mid+1;
            else high = mid;
        }
        return low-1;
    }
};
