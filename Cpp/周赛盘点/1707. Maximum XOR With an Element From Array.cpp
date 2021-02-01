class Solution {
public:
    class TrieNode{
    public:
        TrieNode() : left(nullptr), right(nullptr) {}
        
        void insert(int i) {
            TrieNode *p = this;
            for (int k = 31; k >= 0; --k) {
                if (i & (1 << k)) {
                    if (!p->right) p->right = new TrieNode();
                    p = p->right;
                }
                else {
                    if (!p->left) p->left = new TrieNode();
                    p = p->left;
                }
            }
        }
        
        int search(int i) {
            TrieNode *p = this;
            int sum = 0;
            for(int k = 31; k >= 0; k--){
                int tmp = !!(i & (1 << k));
                if (p->left && p->right) {
                    sum += 1 << k;
                    p = tmp ? p->left : p->right;
                }
                else {
                    if (p->left && tmp == 1 || p->right && tmp == 0)
                        sum += 1 << k;
                    p = p->left ? p->left : p->right;
                }
            }
            return sum;
        }
    private:
        TrieNode *left, *right;
    };
    
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        auto cmp = [](const auto &lhs, const auto &rhs) {
          return lhs[1] < rhs[1];  
        };
        for (int i = 0; i < m; ++i) queries[i].push_back(i);
        sort(queries.begin(), queries.end(), cmp);
        
        TrieNode *trie = new TrieNode();
        vector<int> res(m, -1);
        int i = 0, j = 0;
        while (j < m) {
            while (i < n && nums[i] <= queries[j][1]) {
                trie->insert(nums[i++]);
            }
            if (i != 0) res[queries[j][2]] = trie->search(queries[j][0]);
            ++j;
        }
        return res;
    }
};