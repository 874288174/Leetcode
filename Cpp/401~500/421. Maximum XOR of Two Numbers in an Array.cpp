class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode *Trie = new TrieNode(-1);
        for (auto &i : nums) Trie->insert(i);
        int res = 0;
        for (auto &i : nums) {
            res = max(res, Trie->search(i));
        }
        return res;
    }
    
    class TrieNode{
    public:
        TrieNode(int v) : left(nullptr), right(nullptr), val(v) {}
        void insert(int i) {
            TrieNode *p = this;
            for (int k = 31; k >= 0; --k) {
                if (i & (1 << k)) {
                    if (!p->left) p->left = new TrieNode(1);
                    p = p->left;
                } else {
                    if (!p->right) p->right = new TrieNode(0);
                    p = p->right;
                }
            }
        }
        int search(int i) {
            TrieNode *p = this;
            int sum = 0;
            for(int k = 31; k >= 0; k--){
                int tmp = i & (1 << k);
                if (p->left && p->right){
                    p = tmp ? p->right : p->left;
                } 
                else p = p->left ? p->left : p->right;
                sum += tmp ^ (p->val << k);
            }
            return sum;
        }
    private:
        int val;
        TrieNode *left, *right;
    };
};