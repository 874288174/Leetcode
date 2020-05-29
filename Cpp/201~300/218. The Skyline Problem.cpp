class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> edges;
        for(const auto &v : buildings) { 
            edges.push_back(make_pair(v[0], -v[2]));
            edges.push_back(make_pair(v[1], v[2]));
        }
        sort(edges.begin(), edges.end());
        vector<vector<int>> res;
        multiset<int> My_set{0};
        int pre_top = 0;
        for(const auto &e : edges){
            if (e.second < 0)  My_set.insert(-e.second);
            else My_set.erase(My_set.find(e.second));
            int cur_top = *(My_set.rbegin());
            if (cur_top != pre_top){
                res.push_back({e.first, pre_top = cur_top});
            }
        }
        return res;
    }
};