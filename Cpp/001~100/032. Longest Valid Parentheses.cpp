class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, cnt = 0;
        stack<int> S;
        for (auto &c : s){
            if (c == '(') {
                ++cnt;
                S.push(0); 
            }
            else if (S.empty() || !cnt) {
                cnt = 0;
                if( !S.empty() ) S.pop();
            }
            else{
                int cur = 2;
                while( !S.empty() && S.top() ){
                    cur += S.top();
                    S.pop();
                }
                S.pop();
                while( !S.empty() && S.top() ){
                    cur += S.top();
                    S.pop();
                }
                S.push(cur);
                cnt--;
                res = max(res, cur);
            } 
        }
        return res;
    }
};



//////////////////////solution 2/////////////////////////////////////


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
