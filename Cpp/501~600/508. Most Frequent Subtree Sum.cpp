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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> res;
        for (auto &i : m) if (i.second == MaxCnt) {      
            res.push_back(i.first);
        }
        return res;
    }
    
private:
    unordered_map<int, int> m;
    int MaxCnt = 0;
    
    int dfs(TreeNode *root) {
        if (!root) return 0;
        int l = dfs(root->left), r = dfs(root->right);
        int ret = l + r + root->val;
        MaxCnt = max(MaxCnt, ++m[ret]);
        return ret;
    }
};