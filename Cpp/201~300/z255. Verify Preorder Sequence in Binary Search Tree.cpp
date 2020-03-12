/*
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> s;
        int min = INT_MIN;
        for(int i = 0; i < preorder.size(); i++){
            if (preorder[i] < min) return false;
            while (!s.empty() && s.top() < preorder[i]) {
                min = s.top();
                s.pop();
            }
            s.push(preorder[i]);
        }
        return true;
    }
};
*/
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int min = INT_MIN;
        int i = -1;
        for (auto p : preorder) {
            if (p < min) return false;
            while (i >= 0 && p > preorder[i]) {
                min = preorder[i--];
            }
            preorder[++i] = p;
        }
        return true;
    }
};