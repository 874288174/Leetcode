class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        unordered_set<int> Myset;
        for (auto &i : arr) m[i]++;
        for (auto &i : m) {
            if (Myset.count(i.second)) return false;
            Myset.insert(i.second);
        }
        return true;
    }
};