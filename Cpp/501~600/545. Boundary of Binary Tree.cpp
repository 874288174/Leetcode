/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        dfs(root, true, true, res);
        return res;
    }

    void dfs(TreeNode *p, bool leftBound, bool rightBound, vector<int> &res) {
        if (!p) return;
        
        if (leftBound) res.emplace_back(p->val);
        else if (!p->left && !p->right) {
            res.emplace_back(p->val);
            return;
        }
        dfs(p->left, leftBound, !leftBound && rightBound && !p->right, res);
        dfs(p->right, !rightBound && leftBound && !p->left, rightBound, res);
        if (!leftBound && rightBound) {
            res.emplace_back(p->val);
        }
    }
};

 /*
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};
        vector<int> res{root->val}, leaf;
        auto left = get_lr_bound(root->left, true);
        auto right = get_lr_bound(root->right, false);
        get_leaf(root, leaf);
        
        for (auto i : left) res.emplace_back(i);

        for (int i = 0; i < leaf.size(); ++i) {
            if (i == 0 && res.back() == leaf[0]) continue;
            if (i == leaf.size()-1 && !right.empty()) continue;
            res.emplace_back(leaf[i]);
        }
        for (int i = right.size()-1; i >= 0; --i) {
            res.emplace_back(right[i]);
        }
        return res;
    }


    vector<int> get_lr_bound(TreeNode *p, bool flag) {
        vector<int> res;
        while (p) {
            res.push_back(p->val);
            if (flag) {
                if (p->left) p = p->left;
                else p = p->right;
            }
            else {
                if (p->right) p = p->right;
                else p = p->left;
            }
        }
        return res;
    }


    void get_leaf(TreeNode *p, vector<int> &leaf) {
        if (!p) return;
        if (!p->left && !p->right)  leaf.emplace_back(p->val);
        get_leaf(p->left, leaf);
        get_leaf(p->right, leaf);
    }
};
*/