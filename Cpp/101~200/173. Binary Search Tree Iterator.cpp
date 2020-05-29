class BSTIterator {
public:
    stack<TreeNode*> s;
    TreeNode *q;
    BSTIterator(TreeNode* root) {
        q = root;
    }
    
    /** @return the next smallest number */
    int next() {
        while (q) {
           s.push(q);
           q = q->left;
        }
        q = s.top();
        s.pop();
        int res = q->val;
        q = q->right;
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty() || q;
    }
};