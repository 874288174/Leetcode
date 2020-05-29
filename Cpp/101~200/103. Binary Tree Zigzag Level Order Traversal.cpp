class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        int k = 0;
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
            if (k) reverse(v.begin(), v.end());
            k ^= 1;
            res.push_back(v);
        }
        return res;
    }
};