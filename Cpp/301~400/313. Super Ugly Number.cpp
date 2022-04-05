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


class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(n, 0);
        res[0] = 1;
        
        auto cmp = [&](auto p1, auto p2) {
            return res[p1.first] * primes[p1.second] > res[p2.first] * primes[p2.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        for (int i = 0; i < primes.size(); ++i) pq.emplace(0, i);
        
        int i = 1;
        while (i < n) {
            auto [idx, pos] = pq.top();
            pq.pop();
            
            int num = res[idx] * primes[pos];
            
            //remove duplicate
            if (res[i-1] != num) res[i++] = num;

            pq.emplace(idx+1, pos);
        }
        
        return res[n-1];
    }
};





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
