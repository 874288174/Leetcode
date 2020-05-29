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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode *p = head, *q = p->next;
        while (q) {
           if (q->val != p->val) { 
               p->next = q;
               p = q;
           }
           q = q->next;
        }
        p->next = nullptr;
        return head;
    }
};