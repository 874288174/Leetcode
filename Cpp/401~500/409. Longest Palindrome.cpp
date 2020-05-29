class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for (auto c : s) m[c]++;
        int res = 0;
        for (auto pci : m) {
            res += pci.second/2*2;
            if (res % 2 == 0 && pci.second % 2 == 1) res++; 
        }
        return res;
    }
};