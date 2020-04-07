class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "{";
        for (const auto &a : d) { 
            if ((res.length() < a.length() || res.length() == a.length() && res > a)
                   && check(a, s)) {
                res = a;
            }
        }
        return res == "{" ? "" : res;
    }
    
private:
    bool check(const string &a, const string &s) {
        auto i = a.begin(), j = s.begin();
        while (i != a.end() && j != s.end()) {
            if (*i == *j) ++i;
            ++j;
        }
        return i == a.end();
    }
};