/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        dfs(root, target);
        return res;
    }
    
private:
    int res;
    double sub = numeric_limits<double>::max();
    
    void dfs(TreeNode* root, double target) {
        if (!root) return;
        if (sub > fabs(target-root->val)) {
            sub = fabs(target-root->val);
            res = root->val;
        }
        if (target > root->val) dfs(root->right, target);
        else if (target < root->val) dfs(root->left, target);
    }
};