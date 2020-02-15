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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int Max = que.front()->val, sz = que.size();
            while (sz--) {
                auto t = que.front();
                if (t->left) que.push(t->left);
                if (t->right) que.push(t->right);
                que.pop();
                Max = max(Max, t->val);
                
            }
            res.push_back(Max);
        }
        return res;
    }
};