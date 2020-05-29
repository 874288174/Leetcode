class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char, int> ch{{'A',0}, {'C',1}, {'G',2}, {'T',3}};
        unordered_map<int, int> My_map;
        vector<string> res;
        int t = 0, i = 0, n = s.length();
        while (i < 9) t = t << 2 | ch[s[i++]];
        while (i < n) {
            t = t << 2 & 0xfffff | ch[s[i++]];
            if (My_map[t]++ == 1) res.push_back(s.substr(i-10, 10));
        }
        return res;
    }
};