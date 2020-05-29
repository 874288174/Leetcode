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
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return;
        ListNode *p = head, *q = p, *head2, *s;
        while (q && q->next) {
            q = q->next->next;
            p = p->next;
        }
        head2 = p;  p = p->next;  head2->next = nullptr;
        while (p) {
            s = p->next;
            p->next = head2->next;
            head2->next= p;
            p = s;
        }
        p = head;  q = head2->next; head2->next = nullptr;
        while (p && q) {
            s = q->next;
            q->next = p->next;
            p->next = q;
            p = p->next->next;
            q = s;
        }  
    }
};