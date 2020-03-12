class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<bool> visited(10, false);
        vector<vector<int>> jumps(10, vector<int>(10, 0));
        jumps[1][3] = jumps[3][1] = 2;
        jumps[4][6] = jumps[6][4] = 5;
        jumps[7][9] = jumps[9][7] = 8;
        jumps[1][7] = jumps[7][1] = 4;
        jumps[2][8] = jumps[8][2] = 5;
        jumps[3][9] = jumps[9][3] = 6;
        jumps[1][9] = jumps[9][1] = jumps[3][7] = jumps[7][3] = 5;
        res += helper(1, 1, m, n, jumps, visited) * 4;
        res += helper(2, 1, m, n, jumps, visited) * 4;
        res += helper(5, 1, m, n, jumps, visited);
        return res;
    }
private:
    int res = 0;
    
    int helper(int num, int len, int m, int n, vector<vector<int>> &jumps, vector<bool> &visited) {
        int ret = 0;
        if (len++ >= m) ++ret;
        if (len > n) return ret;
        visited[num] = true;
        for (int next = 1; next <= 9; ++next) {
            int jump = jumps[num][next];
            if (!visited[next] && (jump == 0 || visited[jump])) {
                ret += helper(next, len, m, n, jumps, visited);
            }
        }
        visited[num] = false;
        return ret;
    }
};