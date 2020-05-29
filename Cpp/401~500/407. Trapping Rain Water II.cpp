class Solution {
public:
    int trapRainWater(vector<vector<int>>& H) {
        int n = H.size(), m = H[0].size();
        priority_queue<node> pq;
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == n-1) {
                for (int j = 0; j < m; j++)  {
                    pq.push({i, j, H[i][j]});
                    H[i][j] = -1;
                }
            } else {
                pq.emplace(i, 0, H[i][0]);
                pq.emplace(i, m-1,H[i][m-1]);
                H[i][0] = H[i][m-1] = -1;
            } 
        }
        int res = 0, MIN_height = INT_MIN;
        while (!pq.empty()) {
            node t = pq.top();
            pq.pop();
            MIN_height = max(MIN_height, t.value);
            for (int k = 0; k < 4; k++) {
                int xx = t.x+dx[k], yy = t.y+dy[k];
                if (xx >= 0 && yy >= 0 && xx < n && yy < m && H[xx][yy] >= 0) {
                    if (H[xx][yy] < MIN_height) res += MIN_height-H[xx][yy];
                    pq.emplace(xx, yy, H[xx][yy]);
                    H[xx][yy] = -1;
                }
            }
        }
        return res;
    }

private:
    const int dx[4] = {0,0,1,-1}, dy[4] = {-1,1,0,0};
    
    struct node{
        int x, y, value;
        node(int x, int y, int v) : x(x), y(y), value(v){}
        bool operator < (const node &rhs) const {
            return value > rhs.value;
        }
    };
};
