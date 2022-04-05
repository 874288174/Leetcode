class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        string s, res = "a";
        for (const &str : strs) {
            string r = str;
            reverse(r.begin(), r.end());
            s += max(str, r);
        }
        
        for (int i = 0, st = 0; i < strs.size(); st += strs[i++].size()) {
            string p1 = strs[i], p2 = strs[i];
            reverse(p2.begin(), p2.end());
            string body = s.substr(st + p2.size()) + s.substr(0, st);
            
            for (auto j = 0; j < strs[i].size(); ++j) {
                if (p1[j] >= res[0]) {  
                    res = max(res, p1.substr(j) + body + p1.substr(0, j));
                }
                if (p2[j] >= res[0]) {
                    res = max(res, p2.substr(j) + body + p2.substr(0, j));
                }
            }
        }
        return res;
    }
}