/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> My_Stack;
        My_Stack.push(root);
        while (!My_Stack.empty()) {
            TreeNode *t = My_Stack.top();
            My_Stack.pop();
            if(t == NULL) continue;
            res.push_back(t->val);
            My_Stack.push(t->right);
            My_Stack.push(t->left);
        }
        return res;
    }
};