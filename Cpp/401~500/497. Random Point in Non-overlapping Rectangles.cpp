class Solution {
    vector<vector<int>> &rects;
    mt19937 rng;
    discrete_distribution<int> dist;
    
public:
    Solution(vector<vector<int>>& r) : rects(r), rng(random_device()()) {
        vector<int> weights;
        for (const auto &r : rects) {
            weights.push_back((r[2]-r[0]+1)*(r[3]-r[1]+1));
        }
        dist = discrete_distribution<int>(weights.begin(), weights.end());
    }
    
    vector<int> pick() {
        auto &r = rects[dist(rng)];
        int x = uniform_int_distribution<int>(r[0], r[2])(rng);
        int y = uniform_int_distribution<int>(r[1], r[3])(rng);
        return {x, y};
    }
};