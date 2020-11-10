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
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root, false, false, 0);
        return res;
    }
private:
    int res = 0;
    void dfs(TreeNode *p, bool f0, bool f1, int depth) {
        bool f2 = p->val % 2 == 0;
        if (f0) res += p->val;
        if (p->left) dfs(p->left, f1, f2, depth+1);
        if (p->right) dfs(p->right, f1, f2, depth+1);
    }
};


class Solution {
public:
    int sumEvenGrandparent(TreeNode* root, int p = 1, int gp = 1) {
        return root ? sumEvenGrandparent(root->left, root->val, p)
               + sumEvenGrandparent(root->right, root->val, p)
               + (gp % 2 ? 0 : root->val)  : 0;
    }
};