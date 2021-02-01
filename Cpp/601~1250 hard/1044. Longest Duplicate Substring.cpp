class RollingHash {
    using ul = unsigned long;
    ul p = 31,  m = 1e9 + 7;
    vector<ul> hashMap, pPower;
    
    
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
};

class Solution {  
    using ul = unsigned long;
    int dupSubstrK(RollingHash &rs, string &s, int k) {
        unordered_multimap<ul, int> mp;
        for (int i = 0; i + k <= s.size(); ++i) {
            ul key = rs.getHashCode(i, i+k);
            auto range = mp.equal_range(key);
            for (auto it = range.first; it != range.second; ++it) {
                if (s.substr(it->second, k) == s.substr(i, k)) {
                    return i;
                }
            }
            mp.emplace(key, i);
        }
        return -1;
    }
        
public:
    string longestDupSubstring(string S) {
        RollingHash rs(S);
        int start = 0;
        int left = 0, right = S.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            int tmp = dupSubstrK(rs, S, mid);
            if (tmp != -1) {
                left = mid+1;
                start = tmp;
            }
            else right = mid;
        }
        return S.substr(start, left-1);
    }
};