class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> vec(256, 0);
        for (const auto &c : magazine) vec[c]++;
        for (const auto &c : ransomNote) {
           if (--vec[c] < 0) return false;
        }
        return true;
    }
};