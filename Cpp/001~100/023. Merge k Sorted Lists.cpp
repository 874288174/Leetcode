/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct cmp{
    bool operator() (ListNode *lh, ListNode *rh) const{
      return lh->val > rh->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(-1), *p = &dummy;
        priority_queue< ListNode*, vector<ListNode*>, cmp > pq;
        for(auto &i : lists) if(i){ 
            pq.push(i);
        }
        while(!pq.empty()){
            auto t = pq.top();  pq.pop();
            p->next = t;
            p = t;
            t = t->next;
            if(t) pq.push(t);
        }
        return dummy.next;
    }
};