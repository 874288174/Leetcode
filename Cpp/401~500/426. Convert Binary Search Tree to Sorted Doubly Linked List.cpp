/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        auto p = f(root);
        LinkTwoNode(p.second, p.first);
        return p.first;
    }
private:
    pair<Node*, Node*> f(Node *p) {
        if (!p) return {nullptr, nullptr};
        auto left = f(p->left), right = f(p->right);
        if (left.first) LinkTwoNode(left.second, p);
        else left.first = p;

        if (right.second) LinkTwoNode(p, right.first);
        else right.second = p;
        return {left.first, right.second};
    }
    
    void LinkTwoNode(Node *a, Node *b) {
        a->right = b;
        b->left = a;
    }
};