class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        string s;
        dfs(s, 0, digits, res);
        return res;
    }
private:
    string a[8] = {"abc", "def", "ghi", "jkl",
                   "mno", "pqrs", "tuv", "wxyz"};
    
    void dfs(string s, int i, string &digits, vector<string> &res){
        if (i == digits.length()) res.push_back(s); 
        else for(auto c : a[digits[i]-'2']){
            dfs(s+c, i+1, digits, res);
        }
    }
};