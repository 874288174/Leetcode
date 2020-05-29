class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<bool> stk;
        stringstream ss(preorder+',');
        char c;
        while (ss >> c) {
            bool Isdigit = isdigit(c);
            while(c != ',') ss >> c;
            if (!insert(stk, Isdigit)) return false;
        }
        return stk.size() == 1 && stk.top() == false;
    }
    
private:
    bool insert(stack<bool> &stk, bool Isdigit) {
        if (Isdigit) stk.push(true);
        else if (!stk.empty() && stk.top() == false) {
            stk.pop();
            if (stk.empty() || stk.top() != true) return false;
            stk.pop();
            return insert(stk, Isdigit);
        }
        else stk.push(false);
        return true;
    }
};