class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& es) {
        for (int i = 0; i < es.size(); ++i) es[i].push_back(i);
        sort(es.begin(), es.end(), [](const auto &lhs, const auto &rhs) {
            return lhs[2] < rhs[2];
        });
        
        int minMST = MST(n, es, -1, -1);    
        vector<vector<int>> res(2);
        
        for (int i = 0; i < es.size(); ++i) {
            if (minMST < MST(n, es, i, -1)) res[0].push_back(es[i][3]);
            else if (minMST == MST(n, es, -1, i)) res[1].push_back(es[i][3]);
        }
        return res;
    }
    
private:
    int MST(int n, const vector<vector<int>>& es, int not_use, int must_use) {
        vector<int> fa(n);
        for (int i = 0; i < n; ++i) fa[i] = i;
        int res = 0, cnt = 0;
    
        if (must_use != -1) {
            fa[es[must_use][0]] = fa[es[must_use][1]];
            res += es[must_use][2];
            cnt = 1;
        }
        
        for (int i = 0; i < es.size(); ++i) {
            if (i == not_use || i == must_use) continue;
            const vector<int> &t = es[i];
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