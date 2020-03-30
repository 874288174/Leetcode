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
    vector<int> findMode(TreeNode* p) {
        int cnt = 0, maxcnt = 0, cur = 0;
        vector<int> res;
        stack<TreeNode*> stk;
        while (!stk.empty() || p) {
           while (p) {
               stk.push(p);
               p = p->left;
           }   
           p = stk.top();
           if (p->val != cur) {
               cnt = 0;
               cur = p->val;
           }
           if (++cnt > maxcnt) {
               res.clear();
               res.push_back(cur);
               maxcnt = cnt;
           }
           else if (cnt == maxcnt) res.push_back(cur);
           stk.pop();
           p = p->right;
        }
        return res;
    }
};