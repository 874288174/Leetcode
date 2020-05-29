class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new  ListNode(-1);
        dummy->next = head;  head = dummy;
        ListNode *p = dummy, *q = dummy->next;
        
        while (q) {
           bool duplicated = false;
           while(q->next && p->next->val == q->next->val) {
               duplicated = true;
               q = q->next;
           }
           if (!duplicated) {head->next = q; head = q;}
           p = q;
           q = q->next;
        }
        head->next = nullptr;
        return dummy->next;
    }
};




/////////////////////ตÝน้///////////////////////////////////////////

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *p = head->next;
        if (head->val == p->val) {
            while (p && head->val == p->val) {
                ListNode *t = p;
                p = p->next;
                delete(t);
            }
            delete(head);
            return deleteDuplicates(p);
        }
        else {
            head->next = deleteDuplicates(p);
            return head;
        }
    }
};