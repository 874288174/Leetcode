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
    ListNode* sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *mid = find_mid(head), *head2 = mid->next;
        mid->next = nullptr; 
        return merge_two_lists(sortList(head), sortList(head2));
    }
    
private:
    ListNode *merge_two_lists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1), *p = dummy;
        while (l1 && l2) {
            if (l1->val > l2->val) swap(l1, l2);
            p->next = l1;
            p = l1;
            l1 = l1->next;  
        }
        p->next = l1 == nullptr ? l2: l1;
        return dummy->next;
    }
    
    ListNode *find_mid(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};