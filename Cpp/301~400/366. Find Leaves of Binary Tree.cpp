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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root);
        for (auto &it : mp) res.push_back(it.second);
        return res;
    }
    
private:
    map<int, vector<int>> mp;
    
    int dfs(TreeNode *p) {
        if (!p) return 0;
        int l = dfs(p->left), r = dfs(p->right);
        int depth = (!l && !r) ? 1 : max(l, r);
        mp[depth].push_back(p->val);
        return depth+1;
    }
};