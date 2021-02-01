//O(nlogn)
class Solution {
public:
    struct node {
        int val, sz; 
        node (int a, int b) : val(a), sz(b) {} 
        bool operator < (const node &rhs) const {
            if (val != rhs.val) return val > rhs.val;
            else return sz < rhs.sz;
        }
    };
    
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (k == 1) return true;
        sort(nums.begin(), nums.end());
        priority_queue<node> pq;
        for (auto i : nums) {
            if (pq.empty()) pq.emplace(i, 1);
            else if (pq.top().val == i-1) {
                if (pq.top().sz == k-1) pq.pop();
                else {
                    node t(pq.top().val+1, pq.top().sz+1);
                    pq.pop();
                    pq.push(t);
                }
            }
            else pq.emplace(i, 1);
        }
        return pq.empty();
    }
};




//O(n) 每个节点访问最多删2次
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i : nums) ++mp[i];
        for (int i : nums) {
            if (!mp.count(i)) continue;
            int start = i;
            
            while (mp.count(start - 1)) --start;
            for (; start <= i; ++start) {
                if (!mp.count(start)) continue;
                int cnt = mp[start];
                for (int j = start; j < start + k; j++) {
                    if ((mp[j] -= cnt) < 0) return false;
                    else if (mp[j] == 0) mp.erase(j);
                }
            }
        }
        return true;
    }
};

