class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int even = 0, odd = 0;
        for (auto i : chips) {
            i % 2 ? odd++ : even++;
        }
        return min(even, odd);
    }
};