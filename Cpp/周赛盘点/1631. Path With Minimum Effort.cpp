class Solution {
public:
    int n, m;
    const int dirs[5] = {-1,0,1,0,-1};
    vector<vector<bool>> v;
    
	bool dfs(int i,int j, int mid, vector<vector<int>> &h) {
		if (i == n-1 && j == m-1) return true;
		v[i][j] = true;
		bool ok = false;
		for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k+1];
            if (x >= n || y >= m || x < 0 || y < 0) continue;
            if (v[x][y] || abs(h[i][j]-h[x][y]) > mid) continue;
            if (dfs(x, y, mid, h)) {
                ok = true;
                break;
            }
        }
        return ok;
	}

	int minimumEffortPath(vector<vector<int>>& h) {
		int low = 0, high = INT_MAX;
        n = h.size(), m = h[0].size();
        v.resize(n, vector<bool> (m));
		while(low <= high) {
			int mid = low + (high-low) / 2;
            for (auto &t : v) fill(t.begin(), t.end(), 0);
			if (dfs(0, 0, mid, h)) 
                high = mid-1;
			else low = mid+1;
		}
		return low;
	}
};






class Solution {
public:
    using arr3 = array<int, 3>;
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size(), m = h[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 1000000));
        vector<int> dir{0, 1, 0, -1, 0};
        auto cmp = [&](const auto &p1, const auto &p2) { return p1[0] >= p2[0]; };
        priority_queue<arr3, vector<arr3>, decltype(cmp)> pq(cmp);
        dis[0][0] = 0;
        pq.push({0, 0, 0});
        while (!pq.empty()) {
           auto [e, i, j] = pq.top();
           pq.pop();
           if (i == n-1 && j == m-1) break;
           for (int d = 0; d < 4; ++d) {
               int x = i + dir[d], y = j + dir[d + 1];
               if (x >= 0 && y >= 0 && x < n && y < m) {
                   int d = max(dis[i][j], abs(h[i][j] - h[x][y]));
                   if (d < dis[x][y]) {
                       dis[x][y] = d;
                       pq.push({d, x, y});
                   }
               }
            }
        }
        return dis[n-1][m-1];
    }
};


