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
    int maxSumBST(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return res;
    }
private:
    int res = 0;
    
    tuple<bool, int, int, int> dfs(TreeNode *p) {
        if (!p->left && !p->right) {
            res = max(res, p->val);
            return make_tuple(true, p->val, p->val, p->val);
        }
        auto l = p->left ? dfs(p->left) : make_tuple(true, p->val, p->val-1, 0);
        auto r = p->right ? dfs(p->right) : make_tuple(true, p->val+1, p->val, 0);
        bool ok = get<0>(l) && get<0>(r);
        if (!ok) return make_tuple(false, 0, 0, 0);
        else if (get<2>(l) >= p->val || p->val >= get<1>(r)) return make_tuple(false, 0, 0, 0);
        else {
            int t = get<3>(l) + get<3>(r) + p->val;
            res = max(res, t);
            return make_tuple(true, get<1>(l), get<2>(r), t);
        }
    }
};



class Solution {
public:
    struct BSTNode {
        bool isBST;
        int mn;
        int mx;
        int sum;
    };
    BSTNode findMaxBST(TreeNode* node, int& res) {
        if (node != nullptr) {
            BSTNode left = findMaxBST(node -> left, res);
            BSTNode right = findMaxBST(node -> right, res);
            bool isBST = (left.isBST and right.isBST and left.mx < node -> val and node -> val < right.mn);
            int sum = node -> val + left.sum + right.sum;
            if (isBST) res = max(res, sum);
            return { isBST, min(node -> val, left.mn), max(node -> val, right.mx) , sum};
        } else {
            return { true, INT_MAX, INT_MIN, 0};
        }
    }
    int maxSumBST(TreeNode* root) {
        int res = 0;
        findMaxBST(root, res);
        return res;
    }
};