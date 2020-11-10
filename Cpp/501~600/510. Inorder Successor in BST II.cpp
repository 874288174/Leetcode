/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node->right) {
            node = node->right;
            while (node->left) node = node->left;
            return node;
        }
        else {
            while (node->parent) {
                auto p = node->parent;
                if (p->left == node) return p;
                node = p;
            }
            return nullptr;
        }
    }
};