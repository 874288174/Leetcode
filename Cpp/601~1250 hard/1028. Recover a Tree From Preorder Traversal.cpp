/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        stringstream ss(s);
        vector<pair<TreeNode*, int>> stk{{new TreeNode(-1), -1}};
        while (ss.peek() != EOF) {
            int cnt = 0, val;
            while (ss.peek() == '-') {
                ++cnt;
                ss.get();
            }
            ss >> val;
            while (stk.back().second >= cnt) stk.pop_back();
            auto &p = stk.back().first->left ? stk.back().first->right : stk.back().first->left;
            stk.emplace_back(p = new TreeNode(val), cnt);
        }
        return stk[1].first;
    }
};