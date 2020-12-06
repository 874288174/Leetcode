/*
三次dfs
第一次从任意点找到最远点a
第二次从a找到最远点b
第三次从b出发

孙氏推论：所有最大直径经过同一个点

该方法可以做 求每一点到所有点的距离中的最大值
*/

class Solution {
public:
    const static int N = 1e5 + 5;
    vector<int> G[N];
    int n, dis[N];
    void dfs(int u, int fa = 0) {
        dis[u] = dis[fa] + 1;
        for(int v : G[u]) if(v != fa) dfs(v, u);
    }
    int mx() {
        int res = 1;
        for(int i = 1; i <= n; i++) if(dis[i] > dis[res]) res = i;
        return res;
    }
    int getsec() {
        int mx1 = 0, mx2 = 0;
        for(int i = 1; i <= n; i++) 
            if(dis[i] > mx1) { mx2 = mx1; mx1 = dis[i]; }
            else if(dis[i] > mx2) mx2 = dis[i];
        return mx2;
    }
    int tree3(vector<int>& e) {
        n = e.size() + 1;
        for(int i = 0; i < e.size(); i++) {
            int u = i + 2, v = e[i];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dis[0] = -1;
        dfs(1);
        int p1 = mx(), t1 = getsec();
        dfs(p1);
        int p2 = mx(), t2 = getsec();
        dfs(p2);
        int t3 = getsec();
        return max({t1, t2, t3});
    }
};