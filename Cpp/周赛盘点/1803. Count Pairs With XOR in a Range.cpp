class Solution {
    struct TrieNode {
        int val, cnt = 0;
        TrieNode *son[2];
    };
    
    void insert(TrieNode* p, int num) {
        for (int k = 15; k >= 0; --k) {
            int flag = (num & (1 << k)) ? 1 : 0;
            if (!p->son[flag]) {
                p->son[flag] = new TrieNode();
            }
            p = p->son[flag];
            p->cnt++;
        }
    }
    
    int search(TrieNode *p, int now, int num, int k, int hi) {
        int flag = (num & (1 << k)) ? 1 : 0;
        int res = 0;
        if (p->son[flag]) {
            if ((now ^ (1 << k)) - 1 <= hi) {
                res += p->son[flag]->cnt;
            } else {
                res += search(p->son[flag], now, num, k - 1, hi);
            }
        }
        if ((now ^ (1 << k)) <= hi) {
            if (p->son[1 - flag])
                res += search(p->son[1 - flag], now ^ (1 << k), num, k - 1, hi);
        }
        return res;
    }
    
    int count(vector<int>& nums, TrieNode* p, int hi) {
        int res = 0;
        for (int num : nums) {
            res += search(p, 0, num, 15, hi);
        }
        return res;
    }
public:
    int countPairs(vector<int>& nums, int low, int high) {
        auto root = new TrieNode();
        
        for (int num : nums) insert(root, num);

        return (count(nums, root, high) - count(nums, root, low - 1)) / 2;
    }
};
