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
    int largestBSTSubtree(TreeNode* root) {
        int sum = 0, Min = INT_MAX, Max = INT_MIN;
        dfs(root, Min, Max, sum);
        return res;
    }
    
private:
    int res = 0;
    bool dfs(TreeNode *root, int &Min, int &Max, int &sum) {
        if (root == nullptr) {
            Min = INT_MAX, Max = INT_MIN, sum = 0;
            return true;
        }
        int l_sum = 0, r_sum = 0;
        int l_min = INT_MAX, r_min  = INT_MAX；
        int l_max = INT_MIN, r_max  = INT_MIN;
        bool l_tree = dfs(root->left, l_min, l_max, l_sum);
        bool r_tree = dfs(root->right, r_min, r_max, r_sum);
        Min = min(Min, min(root->val, l_min));
        Max = max(Max, max(root->val, r_max));
        if (l_tree && r_tree && l_max < root->val && r_min > root->val) {
            res = max(res, sum = l_sum + r_sum+1);
            return true;
        }
        return false;
    }
};