class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<node> v;
        for (int i = 0; i < n; ++i) {
           v.emplace_back(speed[i], efficiency[i]);    
        }
        sort(v.begin(), v.end());
        long long res = 0, sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; ++i) {
            sum += v[i].s;
            pq.push(v[i].s);
            res = max(res, sum * v[i].e);
            if (pq.size() == k) {
                sum -= pq.top();
                pq.pop();
            }
        }
        return res % (int)(1e9 + 7);
    }
    struct node{
        node(int s, int e) : s(s), e(e){}
        int s, e;
        bool operator < (const node &rhs) {
            if (e != rhs.e) return e > rhs.e;
            else return s > rhs.e;
        }
    };
};





class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> ess;
        for (int i = 0; i < n; ++i)
            ess.emplace_back(efficiency[i], speed[i]);
        sort(rbegin(ess), rend(ess));
        long sumS = 0, res = 0;
        priority_queue <int, vector<int>, greater<int>> pq; //min heap
        for(auto& [e, s]: ess){
            pq.emplace(s);
            sumS += s;
            if (pq.size() > k) {
                sumS -= pq.top();
                pq.pop();
            }
            res = max(res, sumS * e);
        }
        return res % (int)(1e9+7);
    }
};