class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int _, int bound_num, int bound_w) {
        int n = boxes.size();
        vector<int> p(n + 1), w(n + 1), neg(n + 1);
        vector<long long> W(n + 1);
        for (int i = 1; i <= n; ++i) {
            p[i] = boxes[i - 1][0];
            w[i] = boxes[i - 1][1];
            if (i > 1) {
                neg[i] = neg[i - 1] + (p[i - 1] != p[i]);
            }
            W[i] = W[i - 1] + w[i];
        }
        
        deque<int> deq{0};
        vector<int> f(n + 1), g(n + 1);
        
        for (int i = 1; i <= n; ++i) {
            while (!deq.empty() && (i - deq.front() > bound_num || W[i] - W[deq.front()] > bound_w)) {
                deq.pop_front();
            }
            
            f[i] = g[deq.front()] + neg[i] + 2;
            
            if (i != n) {
                g[i] = f[i] - neg[i + 1];
                while (!deq.empty() && g[i] <= g[deq.back()]) {
                    deq.pop_back();
                }
                deq.push_back(i);
            }
        }
        
        return f[n];
    }
};