
class Solution {
public:
    int m, n;                      
    const vector<int> dirs{0,0,1,0,-1,0};
    
    int createBitVec(vector<vector<int>>& mat) {
        int bitvec = 0;
        for(int i = 0;i < n; i++) {
            for(int j = 0; j < m; j++) {
                bitvec <<= 1;
                bitvec |= mat[i][j];
            }
        }
        return bitvec;
    }
    
    int getFlip(int i, int j, int bitVec) {
        for (int d = 0; d < 5; d++) {
            int x = i+dirs[d], y = j+dirs[d+1];
            if (x >= 0 && y >= 0 && x < n && y < m) {
                bitVec ^= 1<<(x*m+y);
            }        
        }
        return bitVec;
    }
    
    int minFlips(vector<vector<int>>& mat) {
        n = mat.size(), m = mat[0].size();
        int bitvec = createBitVec(mat), cnt = 0;
        if (!bitvec) return 0;
        queue<int> q;
        unordered_set<int> vis;                      
        q.push(bitvec);						
        while (!q.empty()) {
            int sz = q.size();
            ++cnt;
            while (sz--) {
                auto u = q.front();
                q.pop();
                for (int i = 0; i < n; i++) {                 
                    for (int j = 0; j < m; j++) {
                        int t = getFlip(i, j, u);
                        if (!t) return cnt;
                        if (!vis.count(t)) {
                            q.push(t);
                            vis.insert(t);
                        }
                    }
                }
            }
            
        }
        return -1;   
    }
};