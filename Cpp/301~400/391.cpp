class Solution {
public:
    using pii = pair<int, int>;
    
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        auto cmp = [](const pii& a, const pii& b) { 
            return a.second <= b.first; 
        };
        int area = 0;
        int xmin = INT_MAX, ymin = INT_MAX;
        int xmax = INT_MIN, ymax = INT_MIN;
        vector<vector<int>> verticalEdges;     
        multiset<pii, decltype(cmp)> s(cmp);
        
        for (const auto &v : rectangles) {
            area += (v[2] - v[0]) * (v[3] - v[1]);
            xmin = min(xmin, v[0]), ymin = min(ymin, v[1]); 
            xmax = max(xmax, v[2]), ymax = max(ymax, v[3]);
            verticalEdges.push_back({v[0], 1, v[1], v[3]});
            verticalEdges.push_back({v[2], -1, v[1], v[3]});
        }
        if (area != (xmax - xmin) * (ymax - ymin)) return false;
        
        sort(verticalEdges.begin(), verticalEdges.end());
        for (const auto &v : verticalEdges) {
            auto it = s.find({v[2], v[3]});
            if (v[1] > 0) {
                if (it != s.end())  return false;     
                s.insert({v[2], v[3]});
            } 
            else s.erase(it); 
        }
        return true;
    }   
};

















class Solution {
    struct pairhash {
        template <typename T, typename U>
        size_t operator()(const pair<T, U> &p) const {
            size_t l = hash<T>()(p.first), r = hash<U>()(p.second);
            return l + 0x9e3779b9 + (r << 6) + (r >> 2);
        }
    };
public: 
    using pii = pair<int, int>;

    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int area = 0;
        int xmin = INT_MAX, ymin = INT_MAX;
        int xmax = INT_MIN, ymax = INT_MIN;
        unordered_map<pii, int, pairhash> m;
        
        vector<pii> points = {{0, 1}, {0, 3}, {2, 3}, {2, 1}};
        for (const auto &v : rectangles) {
            for (auto [x, y] : points) {
                if (++m[{v[x], v[y]}] > 4) return false;
            }
            area += (v[2] - v[0]) * (v[3] - v[1]);
            xmin = min(xmin, v[0]), ymin = min(ymin, v[1]);
            xmax = max(xmax, v[2]), ymax = max(ymax, v[3]);
        }
        if (area != (xmax - xmin) * (ymax - ymin)) return false;
        
        unordered_set<pii, pairhash> s 
            = {{xmin, ymin}, {xmin, ymax}, {xmax, ymax}, {xmax, ymin}};
        for (const auto &[pii, cnt] : m) {
            if (cnt & 1 == 1) {
                if (!s.count(pii)) return false;
                s.erase(pii); 
            }
        }
        return s.empty();
    }
};