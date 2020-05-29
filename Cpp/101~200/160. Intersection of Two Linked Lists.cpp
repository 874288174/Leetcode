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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2 = 0;
        ListNode *p = headA, *q = headB;
        while (p) {p = p->next; len1++;} 
        while (q) {q = q->next; len2++;} 
        if (len1 < len2) {
            swap(len1, len2);
            swap(headA, headB);
        }
        
        p = headA; q = headB;
        int k = len1-len2;
        while (k--) p = p->next;
        while (p) {
            if (p == q) return p;
            p = p->next;
            q = q->next;
        }
        return nullptr;
    }
}