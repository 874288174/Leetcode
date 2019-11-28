class Solution {
public:
    bool isValid(string s) {
        stack< char > Stack;
        for(auto &c : s){
           if(c == '(' || c == '{' || c == '[') Stack.push(c);
           else if(!Stack.empty() && (c == ')' && (Stack.top() == '(' ) || (c == ']' && Stack.top() == '[') || (c == '}' && Stack.top() == '{' ) )){
               Stack.pop();
           } 
           else return false;
        }
        if(Stack.empty() ) return true;
        else return false;
    }
};