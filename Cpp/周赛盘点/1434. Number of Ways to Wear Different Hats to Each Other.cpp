class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
		// Time Complexity: O(2^n * h * n)
		// Space Complexity: O(2^n)
		
        vector<vector<int>> persons(40);
        const int n(hats.size()), mod(1e9 + 7);
		
        vector<int> masks(1 << n);
        masks[0] = 1;
        
        for (int i = 0; i < n; ++i)
            for (const int& h: hats[i])
                persons[h - 1].emplace_back(i);
        
        for (int i = 0; i < 40; ++i) {
            for (int j = (1 << n) - 1; j >= 0; --j) {
                for (const int& p: persons[i]) {
                    if ((j & (1 << p)) == 0) {
                        masks[j | (1 << p)] += masks[j];
                        masks[j | (1 << p)] %= mod;
                    }
                }
            }
        }
        return masks[(1 << n) - 1];
    }
};