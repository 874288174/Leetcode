class Solution {
public:
    unordered_map<char, char> mp{{'{', '}'}, {'(', ')'}, {'[', ']'}};

    bool isValid(string s) {
        stack<char> Stack;
        for (auto c : s){
           if (mp.count(c)) Stack.push(c);
           else if (!Stack.empty() && mp[Stack.top()] == c) {
               Stack.pop();
           } 
           else return false;
        }
        return Stack.empty();
    }
};