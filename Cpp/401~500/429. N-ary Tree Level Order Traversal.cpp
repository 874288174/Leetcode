/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> vect;
            while (sz--) {
                vect.push_back(q.front()->val);
                auto &child = q.front()->children;
                q.pop();
                for (auto &i : child) q.push(i);
            }
            res.push_back(vect);
        }
        return res;
    }
};