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