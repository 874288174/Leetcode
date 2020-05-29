class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                TreeNode *t = q.front();
                q.pop();
                if (t->left == nullptr && t->right == nullptr) return res;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res++;
        }
        return -1;
    }   
};