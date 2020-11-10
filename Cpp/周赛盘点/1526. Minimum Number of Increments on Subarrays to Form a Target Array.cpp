class Solution {
public:
    int minNumberOperations(vector<int>& v) {
        int res  = v[0];
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] > v[i-1]) res += v[i] - v[i-1];
        }
        return res;
    }
};