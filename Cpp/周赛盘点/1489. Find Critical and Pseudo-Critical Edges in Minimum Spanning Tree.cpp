class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for (int i = 0; i < m; ++i) edges[i].push_back(i);
        auto cmp = [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[2] < rhs[2];
        };
        sort(edges.begin(), edges.end(),  cmp);
        int minMST = MST(n, edges, -1, -1);    
        vector<vector<int>> res(2);
        for (int i = 0; i < m; ++i) {
            if (minMST < MST(n, edges, i, -1)) 
                res[0].push_back(edges[i][3]);
            else if (minMST == MST(n, edges, -1, i)) 
                res[1].push_back(edges[i][3]);
        }
        return res;
    }
private:
    int MST(int n, const vector<vector<int>>& edges, int not_use, int must_use) {
        vector<int> fa(n, -1);
        int res = 0, cnt = 0;
        if (must_use != -1) {
            Union(edges[must_use][0], edges[must_use][1], fa);
            res += edges[must_use][2];
            cnt = 1;
        }
        for (int i = 0; i < edges.size(); ++i) {
            if (i == not_use || i == must_use) continue;
            const vector<int> &t = edges[i];
            if (!Union(t[0], t[1], fa)) continue;
            res += t[2];
            ++cnt;
        }
        return cnt == n-1 ? res : INT_MAX;  
    }
    int find(int x, vector<int> &fa) {
        return fa[x] < 0 ? x : (fa[x] = find(fa[x], fa));
    }

    bool Union(int x, int y, vector<int> &fa) {
        int fax = find(x, fa), fay = find(y, fa);
        if (fax == fay) return false;
        fa[fax] += fa[fay];
        fa[fay] = fax;
        return true;
    }
};
