class Solution {
public:
    int checkRecord(int n) {
        if (n <= 0) return 0;
        vector<long long> pre(6, 0);
        pre[0] = 1;
        while (n--) {
            vector<long long> cur(6, 0);
            
            cur[0] = pre[0] + pre[1] + pre[2];
            cur[3] = cur[0] + pre[3] + pre[4] + pre[5];
            
            for (int k = 0; k < 6; k++) {
                if (k % 3 == 0) continue; 
                cur[k] += pre[k-1];
            }
    
            for (auto &i : cur) i %= 1000000007; 
            pre = cur;
        }
        return (accumulate(pre.begin(), pre.end(), (long long)0)) % 1000000007;
    }
};