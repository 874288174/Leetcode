class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> Myset(candies.begin(), candies.end());
        return min(Myset.size(), candies.size()/2);
    }
};