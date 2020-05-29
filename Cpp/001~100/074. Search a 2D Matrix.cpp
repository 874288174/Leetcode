class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int n = matrix.size(), m  = matrix[0].size();
        int l = 0, r = m*n;
        while (l < r) {
            int mid = l + (r-l)/2;
            int v = matrix[mid/m][mid%m];
            if (v == target) return true;
            else if (v < target) l = mid+1;
            else  r = mid;
        }
        return false;
    }
};