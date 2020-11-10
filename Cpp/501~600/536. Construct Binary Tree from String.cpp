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
    TreeNode* str2tree(string s) {
        if (s.empty()) return nullptr;
        stringstream ss(s);
        return dfs(ss);
    }

    TreeNode *dfs(stringstream &ss) {
        char c;
        int num = 0;
        int isneg = 1;
        if (ss.peek() == '-') {
            ss >> c;
            isneg = -1;
        }

        while (ss >> c && isdigit(c))  num = num*10 + c-'0';
        
        auto p = new TreeNode(isneg * num);
        if (c == '(') {
            p->left = dfs(ss);
            if (ss.peek() == '(') {
                ss >> c;
                p->right = dfs(ss);
            }
            ss >> c;
        }
        return p;
    }
};