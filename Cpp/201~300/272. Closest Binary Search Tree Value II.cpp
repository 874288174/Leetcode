class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top(); s.pop();
            if (res.size() < k) res.push_back(p->val);
            else if (abs(p->val - target) < abs(res[0] - target)) {
                res.erase(res.begin());
                res.push_back(p->val);
            } else break;
            p = p->right;
        }
        return res;
    }
}; 


/*
class Solution {
public:
    struct node {
        double sub;
        int value;
        node(double s, int v):sub(s), value(v){}
        bool operator < (const node &rhs) const {
            return sub < rhs.sub;  
        };
    };
    
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        dfs(root, target, k);
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.top().value);
            q.pop();
        }
        return res;
    }
    
private:
    priority_queue<node> q;
    
    
    void dfs(TreeNode* root, double target, int k) {
        if (!root) return;
        double sub = q.size() < k ? numeric_limits<double>::max() : q.top().sub;
        double a = fabs(target-root->val);
        if (sub > a) {
            q.push({a, root->val});
            if (q.size() > k) q.pop();
        }
        if (q.size() < k || a != q.top().sub || target < root->val)
            dfs(root->left, target, k);
        if (q.size() < k || a != q.top().sub || target > root->val)
            dfs(root->right, target, k);
    }
};
*/