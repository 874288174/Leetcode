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
    vector<TreeNode*> generateTrees(int n) {   
        if (n == 0) return vector<TreeNode*> ();
        vector<vector<vector<TreeNode*>>> dp(n+1,vector<vector<TreeNode*>>(n+1));
        return  generateTrees(1, n, dp);
    } 
    
private:
    vector<TreeNode*> generateTrees(int start, int end, vector<vector<vector<TreeNode*>>> &dp) {
        vector<TreeNode*> subTree;
        if (start > end)  {
            subTree.push_back(nullptr);
            return subTree;
        }
        else if (!dp[start][end].empty()) return dp[start][end];
        else for (int k = start; k <= end; ++k) {
            vector<TreeNode*> leftsubTree = generateTrees(start, k-1, dp);
            vector<TreeNode*> rightsubTree = generateTrees(k+1, end, dp);
            for (auto &i : leftsubTree) {
                for (auto &j : rightsubTree) {
                    TreeNode *t = new TreeNode(k);
                    t->left = i;
                    t->right = j;
                    subTree.push_back(t);
                }
            }
        }
        return dp[start][end] = subTree;
    }
};