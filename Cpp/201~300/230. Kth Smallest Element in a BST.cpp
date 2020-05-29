class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode *p = root;
        while (p || !stk.empty()) {
            while(p) {
                stk.push(p);
                p = p->left;
            }
            p = stk.top(); 
            stk.pop();  
            if(--k == 0) return p->val;
            p = p->right;
        }
        return -1;
    }
};