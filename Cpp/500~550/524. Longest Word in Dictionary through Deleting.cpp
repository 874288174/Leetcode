class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for (auto &a : d) { 
            if (a.length() < res.length()) continue; 
            if (check(a, s) && (res.length() < a.length() || res > a)) {
                res = a;
            }
        }
        return res;
    }
    
private:
    bool check(string &a, string &s) {
        auto i = a.begin(), j = s.begin();
        while (i != a.end() && j != s.end()) {
            if (*i == *j) i++;
            j++;
        }
        return i == a.end();
    }
};