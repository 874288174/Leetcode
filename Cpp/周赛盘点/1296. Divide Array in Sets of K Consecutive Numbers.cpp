class Solution {
public:
    struct node {
        int val, sz;  
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
            if (pq.empty()) pq.push({i, 1});
            else if (pq.top().val == i-1) {
                if (pq.top().sz == k-1) pq.pop();
                else {
                    node t = {pq.top().val+1, pq.top().sz+1};
                    pq.pop();
                    pq.push(t);
                }
            }
            else pq.push({i, 1});
            //cout << pq.size() << "\n";
        }
        return pq.empty();
    }
};



class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int, int> ctr;
        for (int num : nums)
            ctr[num]++;
        for (int num : nums) {
            int start = num;
            while (ctr[start - 1])
                start--;
            for (; start <= num; start++) {
                int times = ctr[start];
                if (times) {
                    for (int victim = start; victim < start + k; victim++) {
                        if (ctr[victim] < times)
                            return false;
                        ctr[victim] -= times;
                    }
                }
            }
        }
        return true;
    }
};