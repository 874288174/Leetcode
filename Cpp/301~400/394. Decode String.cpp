class Solution {
public:
    string decodeString(string s) {
        stack<string> chars;
        stack<int> nums;
        string res;
        int num = 0;
        for(auto &c : s) {
            if (isdigit(c)) num = num*10 + (c-'0');                              
            else if (isalpha(c)) res.push_back(c);                
            else if (c == '[') {
                chars.push(res);
                nums.push(num);
                res = "";
                num = 0;
            }
            else if (c == ']') {
                string tmp = res;
                int k = nums.top(); 
                nums.pop();
                res = chars.top();
                chars.pop();
                while (k--) res += tmp;
            }
        }
        return res;
     }
};