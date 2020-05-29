class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if (strs.empty()) return res;
        int len = strs[0].length();
        for(int i = 0; i < len; i++){
            char c = strs[0][i];
            for(auto &str : strs){
                if(str.length() < i || str[i] != c )  return res;
            }
            res += c;
        }
        return res;
    }
};