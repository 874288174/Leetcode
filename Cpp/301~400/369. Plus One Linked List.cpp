/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode *p, *q = new ListNode(0);
        q->next = head;
        p = head = q ;

        while (q->next) {
            q = q->next;
            if (q->val != 9) p = q;
        }
        q = p->next;
        while (q) {
            q->val = 0;
            q = q->next; 
        }
        ++p->val;
        return head->val ==  0 ? head->next : head;
    }
};