class Solution {
public:
    int dp[10001];
    
    int racecar(int t) {
        if (dp[t] > 0) return dp[t];
        int n = ceil(log2(t+1)), res;
        if (1<<n == t + 1) dp[t] = n;
        else {
            //超过再返回
            dp[t] = racecar((1 << n) - 1 - t) + n + 1;
            //没超过，折返加速m次，再掉头
            for (int m = 0; m < n - 1; ++m)
                dp[t] = min(dp[t], racecar(t - (1 << (n - 1)) + (1 << m)) + n + m + 1);
        }
        return dp[t];
    }
};






class Solution {
public:
    using pii = pair<int, int>;
    
    int racecar(int T) {
        int depth = 0;
        auto myhash = [](const pii& lhs)->size_t {
            return hash<int>()(lhs.first) ^ hash<int>()(lhs.second);
        };
        unordered_set<pii, decltype(myhash)> vis(20, myhash);
        queue<pii> q{{{0,1}}};
        vis.emplace(0, 1);
        while(1) {
            int sz = q.size();
            while (sz--) {
                auto [pos, vel] = q.front();
                q.pop();
                if (pos == T) return depth;
                
                vector<pii> cand;
                if (abs(T - (pos + vel)) < T)
                    cand.emplace_back(pos + vel, 2 * vel);
                cand.emplace_back(pos, vel < 0 ? 1 : -1);
                
                for (auto [pos, vel]: cand)
                    if (!vis.count({pos, vel})) {
                        q.emplace(pos, vel);
                        vis.emplace(pos,vel);
                    }
            }
            ++depth;
        }
        return -1;
    }
};