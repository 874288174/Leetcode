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