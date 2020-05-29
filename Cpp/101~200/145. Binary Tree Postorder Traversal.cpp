class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> My_Stack;
        My_Stack.push(root);
        while (!My_Stack.empty()) {
            TreeNode *t = My_Stack.top();
            My_Stack.pop();
            if(t == NULL) continue;
            res.push_back(t->val);
            My_Stack.push(t->left);
            My_Stack.push(t->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


///////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode *p = root;
        TreeNode *last = NULL;
        while (p || !stk.empty()) {
            while (p) {
                stk.push(p);
                p = p->left;
            } 
            TreeNode *top = stk.top();
            if (top->right && top->right != last) {
                p = top->right;
            }  
            else {
                res.push_back(top->val);
                last = top;
                stk.pop();
            }
        }
        return res;
    }
};
