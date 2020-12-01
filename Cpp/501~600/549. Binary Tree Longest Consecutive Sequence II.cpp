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
    int longestConsecutive(TreeNode* root) {
        dfs(root);
        return res;
    }

private:
    int res = 0;
    
    pair<int, int> dfs(TreeNode *root) {  //{+, -}
        if (!root) return {0, 0};
        pair<int, int> ret = {1, 1};
        auto l = dfs(root->left), r = dfs(root->right);
        if (root->left && root->left->val == root->val+1) 
            ret.first = max(ret.first, l.first+1);
        else l.first = 0;

        if (root->left && root->left->val == root->val-1) 
            ret.second = max(ret.second, l.second+1);
        else l.second = 0;

        if (root->right && root->right->val == root->val+1) 
            ret.first = max(ret.first, r.first+1);
        else r.first = 0;

        if (root->right && root->right->val == root->val-1) 
            ret.second = max(ret.second, r.second+1);
        else r.second = 0;
        
        res = max(res,  1+max(l.first+r.second, l.second+r.first));
        return ret;
    }
};