class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == nullptr) return nullptr;
        RandomListNode *p = head, *q, *head2;
        while (p) {
            q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
        p = head;
        while(p) {
            if(p->random) p->next->random = p->random->next;
            p = p->next->next;
        }
        
        p = head, head2 = head->next;
        while (p) {
            q = p->next; 
            p->next = q->next;
            if(q->next) q->next = q->next->next;
            p = p->next;
        }
        return head2;
    }
};