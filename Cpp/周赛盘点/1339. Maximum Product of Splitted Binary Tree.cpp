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
    int maxProduct(TreeNode* root) {
        S = calSum(root);
        dfs(root);
        return res % MOD;
    }

private:
    long long MOD = 1e9 + 7;
    long long S;
    long long res = -1;
    long long calSum(TreeNode *p) {
        if (!p) return 0;
        return p->val + calSum(p->left) + calSum(p->right);
    }
    
    int dfs(TreeNode *p) {
        if (!p) return 0;
        long long left = dfs(p->left);
        long long right = dfs(p->right);
        res = max(res, left*(S-left));
        res = max(res, right*(S-right));
        return left + right + p->val;
    }
};




class Solution {
public:
    long res = 0, total = 0, sub;
    int maxProduct(TreeNode* root) {
        total = s(root), s(root);
        return res % (int)(1e9 + 7);
    }

    int s(TreeNode* root) {
        if (!root) return 0;
        sub = root->val + s(root->left) + s(root->right);
        res = max(res, sub * (total - sub));
        return sub;
    }
};