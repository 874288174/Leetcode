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
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {                           
        ListNode *res = new ListNode(-1), *p = res; 
        int c = 0;
        while (l1 || l2){
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;         
            p->next = new ListNode((c + a + b) % 10);
            c = (c + a + b) / 10;
            p = p->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (c > 0)   p->next = new ListNode(c);                              
        return res->next;
    }
};