//O（N^3）
class Solution {
public:
    const double tol = 1e-6;
    struct Point {
        Point() {}
        Point(double a, double b) : x(a), y(b) {}
        double x, y;
    };
    
    vector<Point> pnt;
    
    double dis(const Point& a, const Point& b) {
        return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    }

	pair<Point, Point> getCenter(const Point& a, const Point& b, int R) {
		Point mid((a.x + b.x) / 2, (a.y + b.y) / 2);
		double theta = atan2(a.y - b.y, b.x - a.x);
		double tmp = dis(a, b) / 2;
		double d = sqrt(R * R - tmp*tmp);
		Point t0 = {mid.x - d*sin(theta), mid.y - d*cos(theta)};
		Point t1 = {mid.x + d*sin(theta), mid.y + d*cos(theta)};
		return {t0, t1};
	}

	int numPoints(vector<vector<int>>& points, int R) {
		int n = points.size();
		for (const auto &p : points) {
			pnt.emplace_back(p[0], p[1]);
		}
		int ans = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j || dis(pnt[i], pnt[j]) - 2*R > tol) continue;
				int c0 = 0, c1 = 0;
				auto p = getCenter(pnt[i], pnt[j], R);
				for (int k = 0; k < n; k++) {
					if (dis(pnt[k], p.first) - R <= tol) ++c0;
                    if (dis(pnt[k], p.second) - R <= tol) ++c1;
				}
				ans = max({ans, c0, c1});
			}
		}
		return ans;
	}
};




//O(N^2logN)
class Solution {
public:
    using pdb = pair<double, bool>;

    double getDist(const vector<int> &a, const vector<int> &b) {
        return sqrt((a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]));
    }
    
    int numPoints(vector<vector<int>>& p, int r) {
        int n = p.size();
        vector<vector<double>> dist(n, vector<double>(n));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = dist[j][i] = getDist(p[i], p[j]);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            vector<pdb> angles;
            
            for (int j = 0; j < n; ++j) {
                if (j != i && dist[i][j] <= 2 * r) {
                    double A = atan2(p[j][1] - p[i][1], p[j][0] - p[i][0]);
                    double B = acos(dist[i][j] / (2.0 * r));
                    double alpha = A-B, beta = A+B; 
                    angles.emplace_back(alpha, false); 
                    // "false" means this point is entering
                    angles.emplace_back(beta, true); 
                    // "true" means this point is exiting
                }
            }
            
            sort(angles.begin(), angles.end());
            
            int res = 1, cnt = 1;
            for (const auto &[a, b] : angles) { 
                res = max(res, b ? --cnt : ++cnt);
            } 
        }
        return res;
    }
};