class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int res = 0;
        for(auto i : initialBoxes) {
            res += dfs(i, status, candies, keys, containedBoxes);
        }
        return res;
    }
private:
    unordered_set<int> locked;
    
    int dfs(int i, vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes) {
        if (status[i] == 0) locked.insert(i);
        if (status[i] <= 0) return 0;
        int res = candies[i];
        status[i] = -1;
        vector<int> &t = containedBoxes[i];
        for (auto j : keys[i]) {
            if (status[j] == 0) {
                status[j] = 1;
                if (locked.count(j)) {
                    locked.erase(j);
                    t.push_back(j);
                }
            }
        }
        return  res + maxCandies(status, candies, keys, containedBoxes, t);
    }
};