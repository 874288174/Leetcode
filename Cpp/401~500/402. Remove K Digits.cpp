class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";    
        for (char c : num) {
            while (!res.empty() && res.back() > c && k) {
               res.pop_back();     
               k--;                                     
           }
           if (!res.empty() || c != '0') res.push_back(c);
       }
       while (!res.empty() && k--) res.pop_back();    
       return res.empty() ? "0" : res;
    }
};
