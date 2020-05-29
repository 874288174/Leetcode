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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *cur = root, *last = nullptr;
        vector<TreeNode*> pathp, pathq, temp;
        while (pathp.empty() || pathq.empty()) {
            while (cur) {
                temp.push_back(cur);
                if (temp.back() == p) pathp=temp; // check and set path for p
                if (temp.back() == q) pathq=temp; // check and set path for q
                cur = cur->left;
            }
            if (temp.back()->right && temp.back()->right != last) 
                cur=temp.back()->right;
            else {
                last = temp.back();
                temp.pop_back();
            }
        }    
        // compare paths and get lowest common ancestor
        int n = min(pathp.size(), pathq.size());
        for (int i = 1; i < n; i++) {
            if (pathp[i] != pathq[i]) return pathp[i-1];
        }
        return pathp[n-1];
    }
};
/*
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if (!root || root == p || root == q) return root;
       TreeNode *left = lowestCommonAncestor(root->left, p, q);
       TreeNode *right = lowestCommonAncestor(root->right, p, q);
       return !left ? right : !right ? left : root;
    }
};
*/