/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (!root) return nullptr;
        auto new_root = new TreeNode(root->val);
        vector<TreeNode*> v;
        for (auto i : root->children) v.push_back(encode(i));
        v.push_back(nullptr);
        for (int i = 0; i < v.size()-1; ++i) {
            v[i]->right = v[i+1];
        }
        new_root->left = v[0];
        return new_root;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (!root) return nullptr;
        auto new_root = new Node(root->val);
        vector<Node*> &v = new_root->children;
        auto p = root->left;
        while (p) {
            v.push_back(decode(p));
            p = p->right;
        }
        return new_root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));