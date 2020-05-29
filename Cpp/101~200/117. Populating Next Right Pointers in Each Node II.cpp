class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *dummy = new TreeLinkNode(-1), *p, *q;
        while (root) {
            dummy->next = nullptr; p = dummy; q = root;
            while (q){
                if (q->left) {
                    p->next = q->left;
                    p = p->next;
                }
                if (q->right) {
                    p->next = q->right;
                    p = p->next;
                }
                q = q->next;
            }
            root = dummy->next;
        }
    }
};
