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
    string tree2str(TreeNode* t) {
        if (!t) return "";
        string l = tree2str(t->left);
        string r = tree2str(t->right);
        if (l == "" && r == "") return to_string(t->val);
        else if (r == "") return to_string(t->val) + "(" + l + ")";
        else return to_string(t->val) + "(" + l + ")"+ "(" + r + ")";
    }
};