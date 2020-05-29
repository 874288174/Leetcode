class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> v;
            while (sz--) { 
               TreeNode *t = q.front();
               q.pop();
               if (t->left) q.push(t->left);
               if (t->right) q.push(t->right);
               v.push_back(t->val);
            }
            res.push_back(v);
        }
        return res;
    }
};