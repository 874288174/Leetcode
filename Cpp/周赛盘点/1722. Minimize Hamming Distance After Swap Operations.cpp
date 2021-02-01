class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = target.size(), res = 0;
        
        vector<int> fa(n);
        iota(fa.begin(), fa.end(), 0);
        
        for (auto v : allowedSwaps) {
            Union(v[0], v[1], fa);    
        }
        
        unordered_map<int, multiset<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[find(i, fa)].insert(source[i]);
        }
        
        for (int i = 0; i < n; ++i) {
            int t = find(i, fa);
            if (!mp.count(t) || !mp[t].count(target[i])) continue;
            mp[t].erase(mp[t].find(target[i]));
        }
        
        for (const auto &i : mp) {
            res += i.second.size();
        }
        
        return res;
    }
    
    int find(int x, vector<int> &fa) {
        return x == fa[x] ? x : (fa[x] = find(fa[x], fa));    
    }
    
    void Union(int x, int y, vector<int> &fa) {
        int fax = find(x, fa);
        int fay = find(y, fa);
        fa[fax] = fay;
    }
};