class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> My_Stack;
        for(auto &s : tokens) {
            if(!is_operator(s))   My_Stack.push(stoi(s));
            else{
                int b = My_Stack.top(); My_Stack.pop();
                int a = My_Stack.top(); My_Stack.pop();
                switch(s[0]) {
                    case '+' : a += b; break;
                    case '-' : a -= b; break;
                    case '*' : a *= b; break;
                    case '/' : a /= b; break;
                }
                My_Stack.push(a);
            }
        }
        return My_Stack.top();
    }
private:
    bool is_operator(string s){
        return s.length() == 1 && string("+-*/").find(s) != string::npos;
    }
    
};