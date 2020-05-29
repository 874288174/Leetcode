class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(-1), *post, *cur, *last;
        dummy->next = head; 
        head = dummy;
        for (int i = 0; i < m-1; i++) head = head->next;
        last = cur = head->next;
        for (int i = m; i <= n; i++) {
            post = cur->next;
            cur->next = head->next;
            head->next = cur;
            cur = post;
        }
        last->next = cur;
        return dummy->next;
    }
};