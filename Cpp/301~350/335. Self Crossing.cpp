class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        x.insert(x.begin(), 4, 0);
        int i = 4, n = x.size();

        for (; i < n && x[i] > x[i - 2]; i++); //逐渐变大

        if (i == n) return false;

        if (x[i] >= x[i-2] - x[i-4]) x[i-1] -= x[i-3];
        
        for (i++; i < n && x[i] < x[i-2]; i++); //逐渐变小

        return i != n;
    }
};