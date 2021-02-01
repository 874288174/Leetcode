class Solution {
public:
    const int INF = INT_MAX;
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        vector<TreeNode*> stk;
        for (auto &i : nums) {
            TreeNode *cur = new TreeNode(i);
            while (!stk.empty() && stk.back()->val < i) {
                cur->left = stk.back();
                stk.pop_back();
            }
            if (!stk.empty()) stk.back()->right = cur;
            stk.push_back(cur);
        }
        return stk.front();
    }
};