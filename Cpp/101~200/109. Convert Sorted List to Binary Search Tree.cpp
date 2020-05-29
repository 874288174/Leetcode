class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *p = head;
        int len = 0;
        while (p) {
            p = p->next;
            len++;
        }
        return sortedListToBST(head, 0, len-1);
    }
private:
    TreeNode* sortedListToBST(ListNode* &p, int left, int right) {
        if (left > right) return nullptr;
        int mid = left+(right-left)/2;
        TreeNode *left_tree = sortedListToBST(p, left, mid-1);
        TreeNode *node = new TreeNode(p->val);
        p = p->next;
        TreeNode *right_tree = sortedListToBST(p, mid+1, right);
        node->left = left_tree;
        node->right = right_tree;
        return node;
    }    
};