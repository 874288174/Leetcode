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
    int res = 0;
    
    int maxSumBST(TreeNode* root) {
        findMaxBST(root);
        return res;
    }
    
    struct BSTNode {
        bool isBST;
        int mn, mx, sum;
    };
    
    BSTNode findMaxBST(TreeNode* p) {
        if (p == nullptr) return {true, INT_MAX, INT_MIN, 0};
        BSTNode left = findMaxBST(p->left);
        BSTNode right = findMaxBST(p->right);
        bool isBST = left.isBST && right.isBST && left.mx < p->val && p->val < right.mn;
        int sum = p->val + left.sum + right.sum;
        if (isBST) res = max(res, sum);
        return {isBST, min(p->val, left.mn), max(p->val, right.mx), sum};
    }
};