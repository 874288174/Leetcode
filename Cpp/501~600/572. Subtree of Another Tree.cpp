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
        string str = treeTostring(t);
        string treestr = "";
        return findstr(s, treestr, str);
    }
    
private:
    string treeTostring(TreeNode *t) {
        if (!t) return "";
        string l = treeTostring(t->left);
        string r = treeTostring(t->right);
        return l + to_string(t->val) + r;
    }
    
    bool findstr(TreeNode *t, string &treestr, string &s) {
        if (!t) {
            treestr = "";
            return false;
        }
        string l, r;
        if (findstr(t->left, l, s) || findstr(t->right, r, s)) return true;
        treestr = l + to_string(t->val) + r;
        return treestr == s;
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
