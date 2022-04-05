class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int c = *max_element(nums.begin(), nums.end());
        vector<int> g(c + 1);
        
        auto func = [&g](int x, int y) {
            if (!g[y]) g[y] = x;
            else g[y] = gcd(g[y], x);
        };

        for (int x: nums) {
            for (int y = 1; y * y <= x; ++y) {
                if (x % y == 0) {
                    func(x, y);
                    if (y * y != x) func(x, x / y);
                }
            }
        }
        
        int res = 0;
        for (int i = 1; i <= c; ++i) {
            if (g[i] == i) ++res;
        }
        return res;
    }
};









class Solution {
    bool vis[200005];
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        for (int x: nums) vis[x] = true;
        int res = 0;
        for (int i = 1; i <= 200000; ++i){
            int fst = -1;
            for (int j = i; j <= 200000; j += i){
                if (vis[j]) {
                    if (fst == -1) fst = j;
                    else fst = __gcd(fst, j);
                }
            }
            if (fst == i) ++res;
        }
        return res;
    }
};
