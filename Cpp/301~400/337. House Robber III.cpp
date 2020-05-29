class Solution {
public:
    using pii =  pair<int,int>;

    int rob(TreeNode* root) {
        pii res = dfs(root);
        return max(res.first, res.second);
    }
private:
    map<TreeNode*, pii> mp;

    pii dfs(TreeNode* p) {
        if (!p) return {0, 0};
        if (mp.count(p)) return mp[p];
        pii ret(0, p->val);
        if (p->left) {
            auto t = dfs(p->left);
            ret.first += max(t.first, t.second);
            ret.second += t.first;
        }
        if (p->right) {
            auto t = dfs(p->right);
            ret.first += max(t.first, t.second);
            ret.second += t.first;
        }
        return mp[p] = ret;
    }
};
