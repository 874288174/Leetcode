class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = grumpy.size(), res = 0;
        for (int i = 0; i < n; i++) {
            if (!grumpy[i]) res += customers[i];
        }
        int temp = res;
        for (int i = 0; i < n; i++) {
            if (grumpy[i]) temp += customers[i];
            if (X <= i && grumpy[i-X])  temp -= customers[i-X];
            res = max(res, temp);
        }
        return res;
    }
};
