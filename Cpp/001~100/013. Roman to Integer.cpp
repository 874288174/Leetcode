class Solution {
public:
    int romanToInt(string s) {
        if(s.empty()) return 0;
        map<char, int> mp{ {'I',1},{'V',5},{'X', 10},{'L', 50},{'C',100},{'D',500},{'M', 1000} };
        int len = s.length(), res = mp[s[len-1]];
        for(int i = 0; i < len-1; i++){
           if (mp[s[i]] < mp[s[i+1]]) res -= mp[s[i]];
           else res += mp[s[i]];
        }
        return res;
    }
};