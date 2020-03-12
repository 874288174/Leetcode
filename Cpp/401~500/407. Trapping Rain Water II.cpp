class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) return 0;
        n = heightMap.size(), m = heightMap[0].size();
        priority_queue<node> pq;
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == n-1) {
                for (int j = 0; j < m; j++)  {
                    pq.push({i, j, heightMap[i][j]});
                    heightMap[i][j] = -1;
                }
            } else {
                pq.push({i, 0, heightMap[i][0]});
                pq.push({i, m-1, heightMap[i][m-1]});
                heightMap[i][0] = heightMap[i][m-1] = -1;
            } 
        }
        int res = 0, MIN_height = INT_MIN;
        while (!pq.empty()) {
            node t = pq.top();
            pq.pop();
            MIN_height = max(MIN_height, t.value);
            for (int k = 0; k < 4; k++) {
                int xx = t.x+dx[k], yy = t.y+dy[k];
                if (inside(xx, yy) && heightMap[xx][yy] >= 0) {
                    int &h = heightMap[xx][yy];
                    if (h < MIN_height) res += MIN_height-h;
                    pq.push({xx, yy, h});
                    h = -1;
                }
            }
        }
        return res;
    }

private:
    int n, m;
    
    const int dx[4] = {0,0,1,-1};
    const int dy[4] = {-1,1,0,0};
    
    struct node{
        int x, y, value;
        node(int x, int y, int v):x(x), y(y), value(v){}
        bool operator < (const node &rhs) const {
            return value > rhs.value;
        }
    };
    
    bool inside(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }
};