class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        unordered_map<int, vector<int>> mp;
        for (auto v : points) {
            mp[v[1]].push_back(v[0]);
        }
        double mid;
        bool isFirst = true;
        for (auto &i : mp) {
            vector<int> &v = i.second;
            v.erase(unique(v.begin(), v.end()), v.end());
            sort(v.begin(), v.end());
            int l = 0, r = v.size()-1;
            while (l <= r) {
                double m = (v[l++] + v[r--]) / 2.0;
                if (isFirst) {
                    mid = m;
                    isFirst = false;
                }
                if (m != mid) return false;
            }
        }
        return true;
    }
};