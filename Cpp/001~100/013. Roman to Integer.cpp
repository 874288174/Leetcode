class Solution {
public:
    int romanToInt(string s) {
        if(s.empty()) return 0;
        map<char, int> My_map{ {'I',1},{'V',5},{'X', 10},{'L', 50},{'C',100},{'D',500},{'M', 1000} };
        int len = s.length(), res = My_map[s[len-1]];
        for(int i = 0; i < len-1; i++){
           if(My_map[s[i]] < My_map[s[i+1]]) res -= My_map[s[i]];
           else res += My_map[s[i]];
        }
        return res;
    }
};