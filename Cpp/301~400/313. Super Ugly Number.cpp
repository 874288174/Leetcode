class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int sz = primes.size();
        vector<int> k(sz, 0), res(1, 1);
        while (--n) {
            int min_v = INT_MAX; 
            for (int i = 0; i < sz; i++) {
                min_v = min(min_v, primes[i]*res[k[i]]);
            }
            res.push_back(min_v);
            for (int i = 0; i < sz; i++) {
                if (primes[i]*res[k[i]] == min_v)
                    k[i]++;
            }     
        }
        return res.back();
    }
};

/*
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_set<int> My_set;
        pq.push(1);
        while (--n) {
            int t = pq.top();
            pq.pop();
            for (int i : primes) {
                if(INT_MAX / i < t) continue;
                i *= t;
                if (My_set.count(i)) continue;
                My_set.insert(i);
                pq.push(i);
            }
        }
        return pq.top();
    }
};
*/