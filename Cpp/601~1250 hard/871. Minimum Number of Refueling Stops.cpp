//O(n^2)
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int N = stations.size();
        vector<long> dp(N+1);
        dp[0] = startFuel;
        for (int i = 0; i < N; ++i) {
            for (int t = i; t >= 0; --t)
                if (dp[t] >= stations[i][0])
                    dp[t+1] = max(dp[t+1], dp[t] + (long)stations[i][1]);
        }
        for (int i = 0; i <= N; ++i)
            if (dp[i] >= target) return i;
        return -1;
    }
};



//O(NlogN)
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int farest = startFuel;
        int cnt = 0, i = 0, n = stations.size();
        while (farest < target) {
            while (i < n && stations[i][0] <= farest) {
                pq.push(stations[i++][1]);
            }
            if (farest >= target || pq.empty()) break;
            ++cnt;
            farest += pq.top();
            pq.pop();
        }      
        return farest >= target ? cnt : -1;
    }
};
