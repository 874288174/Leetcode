class Solution {
private:
    static constexpr int mod = 1e9 + 7;

public:
    vector<int> numsGame(vector<int>& nums) {
        using LL = long long;
        int n = nums.size();
        for (int i = 0; i < n; ++i) nums[i] -= i;

        priority_queue q0{less{}, vector<LL>{nums[0]}};
        priority_queue q1{greater{}, vector<LL>{}};
        LL sub = -q0.top();
        vector<int> res{0};

        for (int i = 1; i < n; ++i) {
            if (nums[i] <= q0.top()) {
                q0.push(nums[i]);
                sub -= nums[i];
            }
            else {
                q1.push(nums[i]);
                sub += nums[i];
            }
            if (q0.size() == q1.size() + 2) {
                sub += 2*q0.top();
                q1.push(q0.top());
                q0.pop();  
            }
            else if (q0.size() + 1 == q1.size()) {
                sub -= 2*q1.top();
                q0.push(q1.top());
                q1.pop();
            }
            LL delta = sub + ((i & 1) ? 0 : q0.top());
            res.emplace_back(delta % mod);
        }
        return res;
    }
};