class Solution {
public:
    using ll = long long;
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        sort(restrictions.begin(), restrictions.end());
        if (restrictions.empty() || restrictions.back()[0] != n) {
            restrictions.push_back(vector<int> {n, (int)2e9});
        }
        for (int i = restrictions.size()-2; i >= 0; --i) {
            int d = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1] + d);
        }
        
        int prePos = 1, curH = 0, res = 0;
        for (const auto &i : restrictions) {
            int pos = i[0], maxH = i[1];
            int d = pos - prePos;
            int H = curH + d;
    
            if (H > maxH) {
                ll t0 = -curH+maxH, t1 = d;
                res = max(res, int((t0 + t1) / 2 + curH));
            }
            else res = max(res, H);

            curH = min(H, maxH);
            prePos = pos;
        }
        return res;
    }
};