/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string strs = "#" + treeTostring(s) + "#";
        string strt = "#" + treeTostring(t) + "#";
        return strs.find(strt) != string::npos;
    }
    
private:
    string treeTostring(TreeNode *t) {
        if (!t) return "Null";
        string l = treeTostring(t->left);
        string r = treeTostring(t->right);
        return to_string(t->val) + "#" + l + "#" + r;
    }
};
*/

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s) return false;
        return isSameTree(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);
    }
    
private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        else if (!p || !q || p->val != q->val) return false;
        else return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
