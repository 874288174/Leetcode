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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {    
        dfs(root);
        return res;
    }
    
private:
    int cnt = 0;
    unordered_map<string, int> ID;
    unordered_map<int, int> Cnt;
    vector<TreeNode*> res;
        
    int dfs(TreeNode *root) {
        if (!root) return 0;
        int l_tag = dfs(root->left);
        int r_tag = dfs(root->right);
        string t = to_string(root->val) + "," + to_string(l_tag) + "," + to_string(r_tag); 
        if (!ID.count(t)) ID[t] = ++cnt;    
        else if (Cnt[ID[t]]++ == 0) res.push_back(root);
        return ID[t];
    }
};