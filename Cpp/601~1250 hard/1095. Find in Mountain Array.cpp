/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int n;
    
    int findPeak(MountainArray &mountainArr) {
        int low = 0, high = n-1;
        
        while (low < high) {
            int mid = low + (high-low)/2;
            int val = mountainArr.get(mid);
            int next = mountainArr.get(mid+1);
            if (next > val) low = mid+1;
            else high = mid;
        }
        return low;
    }
    
    int findVal(int target, int low, int high, MountainArray &mountainArr, bool up) {
        while (low < high) {
            int mid = low + (high-low)/2;
            int midVal = mountainArr.get(mid);
            if (midVal == target) return mid;
            else if (!up ^ (midVal > target)) high = mid;
            else low = mid+1;
        }
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        n = mountainArr.length();
        int peak = findPeak(mountainArr);
        int pos = findVal(target, 0, peak, mountainArr, true);
        
        if (pos != -1) return pos;
        return findVal(target, peak, n, mountainArr, false);
    }
};