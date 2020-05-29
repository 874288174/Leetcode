class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr || q == nullptr) return p == nullptr && q == nullptr;
        stack<TreeNode*> s;
        s.push(p); s.push(q);
        while (!s.empty()) {
            TreeNode *p = s.top();  s.pop();
            TreeNode *q = s.top();  s.pop();
            if(p->val != q->val) return false;
            if (p->left || q->left) {
                if (!(q->left && q->left)) return false;
                s.push(p->left);
                s.push(q->left);
            }
            if (p->right || q->right) {
                if (!(p->right && q->right)) return false;
                s.push(p->right);
                s.push(q->right);
            }
        }
        return true;
    }
};