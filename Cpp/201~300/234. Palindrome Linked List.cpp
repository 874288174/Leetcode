class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        ListNode *fast = head, *slow = head;
        while (fast && fast->next && fast->next->next) {
            fast = fast-> next->next;
            slow = slow->next;
        }
        ListNode *p = slow->next, *q;
        slow->next = nullptr;
        while (p) {
            q = p->next;
            p->next = slow->next;
            slow->next = p;
            p = q;
        }
        p = head; q = slow->next;
        while (p && q) {
            if (p->val != q->val) return false;
            p = p->next;
            q = q->next;
        }
        return true;    
    }
};