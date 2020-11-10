class Solution {
public:
    using ul = unsigned long;
    static constexpr ul p = 31,  m = 1e9 + 7;
    
    class RollingHash {
    public:
        RollingHash(const string &s) {
            pPower.resize(s.size()+1, 1);
            hashMap.resize(s.size()+1);
            for (int i = 1; i < hashMap.size(); ++i) {
                pPower[i] = (pPower[i-1] * p) % m;
                hashMap[i]= (hashMap[i-1]*p + s[i-1]) % m;
            }
        }
        
        ul getHashCode(int i, int j) {
            if (i == 0) return hashMap[j];
            return (hashMap[j] + m - (hashMap[i]*pPower[j-i])%m) % m;
        }
    private:
        vector<ul> hashMap, pPower;
    };
    
    int distinctEchoSubstrings(string text) {
        RollingHash h(text);
        
        unordered_set<string_view> res;
        const char *p = text.c_str();
        for (int i = 0; i < text.size(); ++i) {
            for (int len = 1; i+len+len <= text.size(); ++len) {
                if (h.getHashCode(i, i+len) == h.getHashCode(i+len, i+len+len)) {
                    res.insert(string_view(p+i, len));
                }
            }
        }
        return res.size();
    }
};