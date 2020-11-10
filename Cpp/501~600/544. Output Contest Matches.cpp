class Solution {
public:
    string findContestMatch(int n) {
        vector<int> v(n+1);
        v[1] = 1;
        return dfs(1, n, 3, v);
    }

    string dfs(int st, int ed, int sum, vector<int> &v) {
        int mid = st+(ed-st)/2;
        v[mid+1] = sum - v[st];
        if (ed == st+1) return "(" + to_string(v[st]) + ","  + to_string(v[ed]) + ")";
        string res = "(";
        res += dfs(st, mid, sum*2-1, v) + ",";
        res += dfs(mid+1, ed, sum*2-1, v) + ")";
        return res;
    }
};