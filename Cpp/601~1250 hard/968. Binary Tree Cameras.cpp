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
    int minCameraCover(TreeNode* root) {
        auto p = dfs(root);
        return min(p[1], p[2]);
    }
    // 0: Strict ST; All nodes below this are covered, but not this one
    // 1: Normal ST; All nodes below and incl this are covered - no camera
    // 2: Placed camera; All nodes below this are covered, plus camera here
    array<int, 3> dfs(TreeNode* p) {
        array<int, 3> res{0, 0, 1000};
        if (!p) return res;
        auto l = dfs(p->left), r = dfs(p->right);
        res[0] = l[1]+r[1];
        res[1] = min({l[2]+r[1], l[1]+r[2], l[2]+r[2]});
        res[2] = 1 + min({l[0], l[1], l[2]}) + min({r[0], r[1], r[2]});
        return res;
    }
};




class Solution {
public:

#define NO_CAMERA       0
#define NOT_NEEDED      1
#define HAS_CAMERA      2

    int res = 0;
    int minCameraCover(TreeNode* root) {
        return  (dfs(root) == NO_CAMERA ? 1 : 0) + res;
    }
    
    int dfs(TreeNode *p) {
        if (!p) return NOT_NEEDED;
        int l = dfs(p->left), r = dfs(p->right);
        
        if (l == NO_CAMERA || r == NO_CAMERA) {
            ++res;
            return HAS_CAMERA;
        } 
        else if (l == HAS_CAMERA || r == HAS_CAMERA) {
            return NOT_NEEDED;
        }
        else return NO_CAMERA;
    }
};
