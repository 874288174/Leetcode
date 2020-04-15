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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) : head(head) {}
    
    /** Returns a random node's value. */
    int getRandom() {
        //在此我扩展为k个随机取样(水塘抽样问题) 
        int k = 1, cnt = 0; 
        vector<int> ret;
        ListNode *cur = head;
        while (cur) {
            if (cnt++ < k) ret.push_back(cur->val);
            else {
               int t = rand() % cnt;
               if (t < k) ret[t] = cur->val;
            }
            cur = cur->next;
        }
        return ret[0];
    }
    
private:
    ListNode *head;
};

//tip 并行水塘抽样  https://www.jianshu.com/p/7a9ea6ece2af 
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */