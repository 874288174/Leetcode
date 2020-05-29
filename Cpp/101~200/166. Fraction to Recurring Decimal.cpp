class Solution {
public:
    string fractionToDecimal(long a, long b) {
        string res = a*b >= 0 ? "": "-", s;
        a = abs(a), b = abs(b);
        res += to_string(a/b);
        if ((a %= b) == 0) return res;
        unordered_map<long, int> My_map;
        int cnt = 0;
        while (!My_map.count(a) && a) {
            My_map.insert({a, cnt++});
            a = a*10;
            s += a/b+'0';
            a %= b;
        }
        if (!a) return res + '.' + s; 
        else return res + '.' + s.substr(0, My_map[a]) + '(' + s.substr(My_map[a]) + ')';
    }
};