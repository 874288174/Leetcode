class Solution {
public:
    double mincostToHireWorkers(vector<int> q, vector<int> w, int K) {
        vector<pair<double,int>> workers;
        for (int i = 0; i < q.size(); ++i)
            workers.emplace_back((double)(w[i]) / q[i], q[i]);
        sort(workers.begin(), workers.end());
        double res = DBL_MAX, sum = 0;
        priority_queue<int> pq;
        for (const auto &worker: workers) {
            sum += worker.second;
            pq.push(worker.second);
            if (pq.size() > K) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == K) res = min(res, sum * worker.first);
        }
        return res;
    }
};