class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = head, *next;
        while (cur) {
            next = cur->next;
            ListNode *p = dummy;
            while (p->next != nullptr && p->next->val < cur->val) p = p->next;
            cur->next = p->next;
            p->next = cur;
            cur = next;
        }
        return dummy->next;
    }
};