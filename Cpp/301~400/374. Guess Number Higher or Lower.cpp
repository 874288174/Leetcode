class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l <= n) {
            int mid = l + (r-l)/2;
            switch(guess(mid)) {    
                case 0: return mid; break;
                case -1: r = mid-1; break;
                case 1: l = mid+1; break;
            } 
        }
        return -1;
    }
};