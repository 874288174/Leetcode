class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> pre{INT_MIN, 0, 0};
        //buy sell cooldown
        for (auto i : prices) {
            vector<int> cur(3);
            cur[0] = max(pre[0], pre[1]-i);
            cur[1] = max(pre[1], pre[2]);
            cur[2] = pre[0]+i;
            pre = std::move(cur);
        }
        return *max_element(pre.begin(), pre.end());
    }
};