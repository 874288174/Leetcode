/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (!root) return res;
        stack<Node*> stk;
        stk.push(root);
        while (!stk.empty()) {
            auto t = stk.top();
            stk.pop();
            res.push_back(t->val);
            for (int i = t->children.size()-1; i >= 0; --i) {
                stk.push(t->children[i]);
            }
        }
        return res;
    }
};