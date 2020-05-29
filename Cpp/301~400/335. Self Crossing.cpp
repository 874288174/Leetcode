class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        x.insert(x.begin(), 4, 0);
        int i = 4, n = x.size();

        while (i < n && x[i] > x[i-2]) ++i; //逐渐变大

        if (i == n) return false;

        if (x[i] >= x[i-2] - x[i-4]) x[i-1] -= x[i-3];
        
        ++i;  // [3, 3, 3, 2, 1, 1] 没有的话相等时会出错
        while (i < n && x[i] < x[i-2]) ++i; //逐渐变小

        return i != n;
    }
};
