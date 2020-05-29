class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        if (points.size() < 4) return points;
        set<vector<int>> myset;
        int left_most = 0, n = points.size();
        for (int i = 0; i < n; i++) {
            if (points[i][0] < points[left_most][0]) {
                left_most = i;
            }
        }
        int p = left_most;
        do {
            int q = (p+1) % n;             //只要不是p点皆可， 如(p+2) % n
            for (int i = 0; i < n; i++) { 
               if (orientation(points[p], points[i], points[q]) < 0) {
                  q = i;
               }
            }
            for (int i = 0; i < n; i++) {
                if (i != p && i != q && orientation(points[p], points[i], points[q]) == 0 && inBetween(points[p], points[i], points[q])) { 
                    myset.insert(points[i]);
                }
            }
            myset.insert(points[q]);
            p = q;
        } while (p != left_most);
        return vector<vector<int>> (myset.begin(), myset.end());
        
    }
private:
    int orientation(vector<int> &p, vector<int> &q, vector<int> &r) {
        return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
    }
    
    bool inBetween(vector<int> &p, vector<int> &i, vector<int> &q) {
        bool a = i[0] >= p[0] && i[0] <= q[0] || i[0] <= p[0] && i[0] >= q[0];
        bool b = i[1] >= p[1] && i[1] <= q[1] || i[1] <= p[1] && i[1] >= q[1];
        return a && b;
    }
};

