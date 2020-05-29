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
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *p, *t;
        p = head;
        while (p) {
            t = p->next;
            p->next = dummy->next;
            dummy->next = p;
            p = t;
            
        }
        return dummy->next;
    }
};