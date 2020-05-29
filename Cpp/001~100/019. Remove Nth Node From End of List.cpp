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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1); 
        dummy.next = head;
        ListNode *pre = &dummy, *p = pre;
        while(n--) p = p->next;
        while(p->next){
           p = p->next;
           pre = pre->next;
        }
        pre->next = pre->next->next;
        return dummy.next;
    }
};