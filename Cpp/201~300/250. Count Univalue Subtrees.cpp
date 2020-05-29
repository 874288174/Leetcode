class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) return 0;
        return f(root, root->val).second;
    }
private:
    pair<bool, int> f(TreeNode *root, int val) {
        if (!root)  return {true, 0};
        auto l = f(root->left, root->val);
        auto r = f(root->right, root->val);
        int res = l.second + r.second;
        if (l.first && r.first) return {root->val == val, res+1};
        else return {false, res};
    }
};