//////////////////////stack/////////////////////////////////////
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, left = -1, n = s.length();
        stack<int> S;
        for (int i = 0; i < n; i++){
            if (s[i] == '(') S.push(i); 
            else if (S.empty()) left = i;
            else {
                S.pop();
                if (S.empty())  res = max(res, i-left);
                else res = max(res, i-S.top());
            }
        }
        return res;
    }
};







//////////////////////dp/////////////////////////////////////
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() <= 1) return 0;    
        int res = 0;
        vector<int> dp(s.size(), 0);
//dp[i] 表示以s[i]结尾最长匹配括号的长度
        for (int i = 1; i < s.length(); i++){    
            if (s[i] == '(') continue;    
            if (s[i-1] == '(') {       
                dp[i] = (i-2) >= 0 ? dp[i-2]+2 : 2;     
                res = max(dp[i], res);
            } else if (i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(') {  
                dp[i] = dp[i-1] + 2+ ((i-dp[i-1]-2>=0) ? dp[i-dp[i-1]-2] : 0);   
                res = max(dp[i], res);           
            }
        }
        return res;    
    }
};

