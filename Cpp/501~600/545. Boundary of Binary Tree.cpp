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