class Solution {
public:
    int nthUglyNumber(int n) {
        vector <int> res (1,1);
        int i = 0, j = 0, k = 0;
        while (--n)
        {
            res.push_back(min(res[i]*2, min(res[j]*3, res[k]*5)));
            if (res.back() == res[i] * 2) ++i;
            if (res.back() == res[j] * 3) ++j;
            if (res.back() == res[k] * 5) ++k;
        }
        return res.back();
    }
};
/*
class Solution {
public:
    using ll = long long;
    
    int nthUglyNumber(int n) {
        ll a[3] = {2, 3, 5};
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        unordered_set<ll> My_set;
        pq.push(1);
        while (--n) {
            int t = pq.top();
            pq.pop();
            for (auto i : a) {
                i *= t;
                if (My_set.count(i)) continue;
                My_set.insert(i);
                pq.push(i);
            }
        }
        return static_cast<int> (pq.top());
    }
};
*/