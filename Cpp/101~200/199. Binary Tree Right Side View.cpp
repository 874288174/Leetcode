class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) { 
               TreeNode *t = q.front();
               q.pop();
               if (t->left) q.push(t->left);
               if (t->right) q.push(t->right);
               if (!sz) res.push_back(t->val);
            }
        }
        return res;
    }
};