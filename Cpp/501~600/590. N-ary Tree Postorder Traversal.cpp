class Solution {
public:
    vector<int> postorder(Node* p) {
        if (!p) return {};
        stack<pair<Node *, size_t>> stk;
        vector<int> res;
        stk.emplace(p, 0);
        while (!stk.empty()) {
            auto &[p, index] = stk.top();
            if (index == p->children.size()) {
                res.push_back(p->val);
                stk.pop();
            } else {
                stk.emplace(p->children[index++], 0);
            }
        }
        return res;
    }
};