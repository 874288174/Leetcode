class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return get_height(root) != -1;
    }
    int get_height(TreeNode *p) {
        if(p == nullptr) return 0;
        int l = get_height(p->left), r = get_height(p->right);
        if (abs(l-r) > 1 || l == -1 || r == -1) return -1;
        else return max(l, r)+1;
    }
};