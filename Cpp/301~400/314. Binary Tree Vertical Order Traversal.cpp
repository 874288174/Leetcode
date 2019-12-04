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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            m[t.second].push_back(t.first->val);
            if (t.first->left) q.push({t.first->left, t.second-1});
            if (t.first->right) q.push({t.first->right, t.second+1});
        }
        for (auto &i : m) res.push_back(i.second);
        return res;
    }
};