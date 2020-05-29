class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), m = p.length();
        vector<int> res;
        unordered_map<char, int> m1, m2;
        for (auto &c : p) m1[c]++;
        int cnt = 0, i = 0, j = 0;
        while(i <= j) {
            while (j < n && cnt < m) {
                if (m1.count(s[j]) && m1[s[j]] >= ++m2[s[j]]) {
                    cnt++;
                }
                j++;
            }
            if (cnt == m && j-i == m) res.push_back(i);
            if (m1.count(s[i]) && m1[s[i]] >= m2[s[i]]--) {
                cnt--;    
            } 
            i++;
        }
        return res;
    }
};