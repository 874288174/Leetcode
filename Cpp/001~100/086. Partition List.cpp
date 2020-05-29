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
    ListNode* partition(ListNode* head, int x) {
       ListNode *L_dummy = new ListNode(-1), *R_dummy = new ListNode(-1);
       ListNode *l = L_dummy, *r = R_dummy, *p = head;
       while (p) {
           if (p->val < x) {
               l->next = p;
               l = p;
           }
           else {
               r->next = p;
               r = p;
           }
           p = p->next; 
       }
       l->next = R_dummy->next;
       r->next = NULL;
       return L_dummy->next; 
    }
};