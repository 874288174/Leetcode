class Solution {
public:
    const int dirs[10] = {0,0,1,0,-1,-1,1,1,-1,0};
    
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        map<int, int> C, R, D0, D1;
        
        auto lightOpt = [&C, &R, &D0, &D1, &N](int x, int y, int on) {
            C[x] += on;
            R[y] += on;
            D0[x+y] += on;
            D1[x-y] += on;
        };
        unordered_set<long long> st;
        for (auto &i : lamps) {
            long long id = 1ll*i[0]*N+i[1];
            st.insert(id);
            lightOpt(i[0], i[1], 1);
        }
        
        vector<int> res;
        for (auto &i : queries) {
            if (C[i[0]] || R[i[1]] || D0[i[0]+i[1]] || D1[i[0]-i[1]])
                res.push_back(1);
            else {
                res.push_back(0);
            }
            for (int k = 0; k < 9; ++k) {
                int x = i[0] + dirs[k];
                int y = i[1] + dirs[k+1];
                if (x < 0 || y < 0 || x >= N || y >= N) continue;
                long long id = 1ll*x*N+y;
                if (!st.count(id)) continue;
                st.erase(id);
                lightOpt(x, y, -1);
            }
        }
        return res;
    }
};