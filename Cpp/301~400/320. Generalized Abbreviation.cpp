class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        if (word.empty()) return {""};
        vector<string> pre{""};
        for(char &c : word) {
            vector<string> cur;
            for (auto &s : pre) {
                cur.push_back(s+c);  
                if (isdigit(s.back())) {
                    int i = s.size()-1;
                    while(i >= 1 && isdigit(s[i-1])) i--;
                    cur.push_back(s.substr(0, i) + to_string(stoi(s.substr(i))+1));
                }  
                else cur.push_back(s+"1");                         
            }
            pre = cur;
        }
        return pre;
    }
};








class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        for (int i = (1 << word.length()) - 1; i >= 0; --i)
            res.emplace_back(f(word, i));
        return res;
    }

   string f(const string &word, int x) {
        string s;
        int cnt = 0, n = word.length();
        for (int i = 0; i < n; ++i, x >>= 1) {
            if ((x & 1) == 0) {
                if (cnt != 0) {
                    s += to_string(cnt);
                    cnt = 0;
                }
                s += word[i];
            }
            else ++cnt;
        }
        if (cnt != 0) s += to_string(cnt);
        return s;
    }
};