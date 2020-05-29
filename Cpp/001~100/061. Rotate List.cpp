class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        int len = 1;
        ListNode *last = head, *p = head;
        while(last->next) {
            last = last->next;
            len++;
        } 
        k = len-k%len;
        while(--k) p = p->next;
        last->next = head;
        head = p->next;
        p->next = nullptr;
        return head;
    }
};