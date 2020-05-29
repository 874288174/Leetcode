class Solution {
public:
    int calculate(string s) { //¼ÓÇ¿°æ¿¼ÂÇ + - * /
        s = '(' + s + ')';
        stack<long> digit;
        stack<char> punct;
        int i = 0, n = s.length();
        while (i < n) {
            if (isspace(s[i])) i++;
            else if (isdigit(s[i])) {
                long temp = 0;
                while (isdigit(s[i])) {
                   temp = temp*10 + s[i++]-'0';
                }
                digit.push(temp);
            }
            else if (s[i] == '(') punct.push(s[i++]);
            else if (s[i] == ')') {
                char c;
                while ((c = punct.top()) != '(') {
                    punct.pop();
                    digit.push(fun(digit, c)); 
                }
                punct.pop();
                i++;
            }
            else if (s[i] == '*' || s[i] == '/') {
                char c;
                while (!punct.empty() && (c = punct.top()) != '(' && c != '+' && c != '-') {// c is '*' or '/'
                    punct.pop();
                    digit.push(fun(digit, c)); 
                }
                punct.push(s[i++]);
            }
            else {
                char c;
                while (!punct.empty() && (c = punct.top()) != '(') {
                    punct.pop();
                    digit.push(fun(digit, c)); 
                }
                punct.push(s[i++]);
            }
        }
        return digit.top();
    }
    
private:
    long fun(stack<long> &digit, char c) {
        long b = digit.top(); digit.pop();
        long a = digit.top(); digit.pop();
        switch (c) {
            case '+' : return a+b;
            case '-' : return a-b;
            case '*' : return a*b;
            case '/' : return a/b;
        } 
        return -1;
    }
};