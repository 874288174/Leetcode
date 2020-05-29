class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m1, m2;
        for(auto &c : s1) m1[c]++;
        int cnt = 0, left = 0;
        int len1 = s1.length(), len2 = s2.length();
        
        for(int i = 0; i < len2; i++) {
            char c = s2[i]; 
            if (m1.count(c)) {
                if (++m2[c] > m1[c]) {
                    while (s2[left] != c) {
                        m2[s2[left++]]--;
                        cnt--;
                    }
                    m2[s2[left++]]--;
                }
                else if (++cnt == len1) return true;
            }
            else {
                left = i+1;
                cnt = 0;
                m2.clear();
            }
        }
        return false;
    }
};