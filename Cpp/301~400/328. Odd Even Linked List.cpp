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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *even = new ListNode(-1), *odd = new ListNode(-1), *q = even, *p = odd, *t = head;
        while (t) {
            p->next = t;
            p = t;
            t = t->next;
            q->next = t;
            q = t;
            if(t) t = t->next;
        }
        p->next = even->next;
        return odd->next;
    }
};