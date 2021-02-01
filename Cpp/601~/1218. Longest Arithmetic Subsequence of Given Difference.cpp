class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int res = 1;
        unordered_map<int, int> m;
        for (auto i : arr) {
            if (!m.count(i-difference)) m[i] = 1;
            else res = max(res, m[i] = m[i-difference]+1);
        }
        return res;
    }
};