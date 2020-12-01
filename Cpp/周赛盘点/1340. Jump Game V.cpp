class Solution {
public:
    array<int, 1001> dp;
    
    int maxJumps(vector<int>& arr, int d) {
        int res = 1;
        for (auto i = 0; i < arr.size(); ++i)
            res = max(res, dfs(arr, i, d));
        return res;
    }
    
    int dfs(vector<int>& arr, int i, int d) {
        if (dp[i]) return dp[i];
        int res = 1, n = arr.size();
        for (auto j = i+1; j <= min(i+d, n-1) && arr[j] < arr[i]; ++j)
            res = max(res, 1 + dfs(arr, j, d));
        for (auto j = i-1; j >= max(0, i - d) && arr[j] < arr[i]; --j)
            res = max(res, 1 + dfs(arr, j, d));
        return dp[i] = res;
    }
};



class Solution {
public:
    struct A {
        int h, i, j = 1;
    };
    
    int maxJumps(vector<int>& arr, int d) {
        vector<A> V;
        int ret = 1, i, n = arr.size(), j, h, vsiz, k, l;
        
        for (i = 0; i < n; ++i) {
            h = arr[i];
            vsiz = V.size();
            
            if (V.empty() || V[vsiz-1].h >= h) {
                V.push_back({h, i, 1});
            } else {
                j = 1;
                while (!V.empty() && V[vsiz-1].h < h) {
                    for (k = vsiz-2; k >= 0 && V[k].h == V[vsiz-1].h; --k);
                    // populate V[l] to left and right
                    for (l = vsiz-1; l > k; --l) {
                        // populate left
                        if (k >= 0 && V[l].i - V[k].i <= d)
                            V[k].j = max(V[k].j, V[l].j + 1);
                        
                        // populate right
                        if (i - V[l].i <= d)
                            j = max(j, V[l].j + 1);
                        
                        // retire
                        ret = max(ret, V[l].j);
                        V.pop_back();
                    }
                    
                    vsiz = V.size();
                }
                
                V.push_back({h, i, j});
            }
        }
        
        // retire the rest
        while (!V.empty()) {
            vsiz = V.size();

            for (k = vsiz-2; k >= 0 && V[k].h == V[vsiz-1].h; --k);
            
            // populate V[l] to left and right
            for (l = vsiz-1; l > k; --l) {
                // populate left
                if (k >= 0 && V[l].i - V[k].i <= d)
                    V[k].j = max(V[k].j, V[l].j + 1);
                        
                // retire
                ret = max(ret, V[l].j);
                V.pop_back();
            }
        }
        
        return ret;
    }
};