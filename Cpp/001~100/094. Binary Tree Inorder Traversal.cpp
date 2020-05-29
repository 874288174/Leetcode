class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> My_Stack;
        TreeNode *p = root;
        while (!My_Stack.empty() || p) {
            while (p) {
                My_Stack.push(p);
                p = p->left;
            }
            p = My_Stack.top();
            My_Stack.pop();
            res.push_back(p->val);
            p = p->right;
        }
        return res;
    }
};