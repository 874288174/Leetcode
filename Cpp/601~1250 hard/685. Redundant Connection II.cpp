class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        //给一棵有向树添加一条边，情况有三种 自己考虑
        int n = edges.size();
        vector<int> fa(n+1), candA, candB;
        // step 1, 找到使得某一结点入度为2的边
        for (auto &edge : edges) {
            if (fa[edge[1]] == 0)
                fa[edge[1]] = edge[0]; 
            else {
                candA = {fa[edge[1]], edge[1]};
                candB = edge;
                //作用 不把candB加入是否满足
                edge[1] = 0;
            }
        } 
        // step 2, union find
        for (int i = 1; i <= n; i++) fa[i] = i;
        for (auto &edge:edges) {
            if (edge[1] == 0) continue;
            int fax = find(edge[0], fa);
            int fay = find(edge[1], fa);
            if (fax == fay) {
                return candA.empty() ? edge : candA;
            }
            fa[fax] = fay;
        }
        return candB;
    }
private:
    int find(int x, vector<int>& fa) {
        return x == fa[x] ? x : fa[x] = find(fa[x], fa);
    }
};