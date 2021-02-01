class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int N, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int n = edgeList.size(), m = queries.size(), i = 0;
        
        auto cmp = [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[2] < rhs[2];
        };
        sort(edgeList.begin(), edgeList.end(), cmp);
        for (int i = 0; i < m; ++i) queries[i].push_back(i);
        sort(queries.begin(), queries.end(), cmp);
        
        vector<bool> res(m);
        vector<int> fa(N, -1);
        
        for (int j = 0; j < m; ++j) {
            while (i < n && edgeList[i][2] < queries[j][2]) {
                Union(edgeList[i][0], edgeList[i][1], fa);
                ++i;
            }
            int fax = find(queries[j][0], fa);
            int fay = find(queries[j][1], fa);
            res[queries[j][3]] = fax == fay;
        }
        
        return res;
    }
    
    void Union(int x, int y, vector<int> &fa) {
        int fax = find(x, fa);
        int fay = find(y, fa);
        if (fax != fay) {
            fa[fay] += fa[fax];
            fa[fax] = fay;
        }
    }
    
    int find(int x, vector<int> &fa) {
        return fa[x] < 0 ? x : (fa[x] = find(fa[x], fa));
    }
};