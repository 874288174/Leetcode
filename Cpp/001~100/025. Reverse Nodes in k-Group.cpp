class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k < 2) return head;
        ListNode *head2 = head, *q;
        for (int i = 1; i < k; i++) {
            head2 = head2->next;
            if (head2 == nullptr) return head;
        }
        
        head2->next = reverseKGroup(head2->next, k);
        while(--k) {
            q = head->next;
            head->next = head2->next;
            head2->next = head;
            head = q;
        }
        return head2;
    }
};