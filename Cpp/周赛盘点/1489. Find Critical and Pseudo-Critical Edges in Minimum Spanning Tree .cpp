class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); ++i) edges[i].push_back(i);
        sort(edges.begin(), edges.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[2] < rhs[2];
        });
        
        int minMST = MST(n, edges, -1, -1);    
        vector<vector<int>> res(2);
        
        for (int i = 0; i < edges.size(); ++i) {
            if (minMST < MST(n, edges, i, -1)) res[0].push_back(edges[i][3]);
            else if (minMST == MST(n, edges, -1, i)) res[1].push_back(edges[i][3]);
        }
        return res;
    }
    
private:
    int MST(int n, const vector<vector<int>>& edges, int not_use, int must_use) {
        vector<int> fa(n);
        for (int i = 0; i < n; ++i) fa[i] = i;
        int res = 0, cnt = 0;
    
        if (must_use != -1) {
            fa[edges[must_use][0]] = fa[edges[must_use][1]];
            res += edges[must_use][2];
            cnt = 1;
        }
        
        for (int i = 0; i < edges.size(); ++i) {
            if (i == not_use || i == must_use) continue;
            const vector<int> &t = edges[i];
            int fax = find(t[0], fa), fay = find(t[1], fa);
            if (fax == fay) continue;
            fa[fax] = fay;
            res += t[2];
            ++cnt;
        }
        return cnt == n-1 ? res : INT_MAX;  
    }

    int find(int x, vector<int> &fa) {
        return x == fa[x] ? x : (fa[x] = find(fa[x], fa));
    }
};