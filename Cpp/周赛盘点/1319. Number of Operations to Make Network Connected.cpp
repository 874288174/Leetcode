class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;
        for (int i = 0; i < n; ++i) fa.push_back(i);
        for (auto &v : connections) {
            Union(fa[v[0]], fa[v[1]]);
        }
        map<int, int> m0, m1;
        
        for (int i = 0; i < n; ++i) {
            int fa = findfa(i);
            m0[fa]++;
        }
        return m0.size() - 1;
    }
private:
    vector<int> fa;
    
    int findfa(int x) {
       return x == fa[x] ? x : (fa[x] = findfa(fa[x]));  
    }
    
    void Union(int x, int y) {
        int fax = findfa(x);
        int fay = findfa(y);
        fa[fax] = fay;
    }
};




class Solution {
public:
    int find(vector<int> &ds, int i) {
        return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        vector<int> ds(n, -1);
        for (auto &c : connections) {
            auto i = find(ds, c[0]), j = find(ds, c[1]);
            if (i != j) {
                if (ds[j] < ds[i])
                    swap(i, j);
                ds[i] += ds[j];
                ds[j] = i;
                --n;
            }
        }
        return n - 1;
    }
};