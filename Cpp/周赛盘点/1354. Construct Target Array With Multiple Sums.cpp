class Solution {
public:
    bool isPossible(vector<int>& A) {
        long total = 0;
        int n = A.size(), a;
        priority_queue<int> pq(A.begin(), A.end());
        for (int a : A)
            total += a;
        while (true) {
            a = pq.top(); pq.pop();
            total -= a;
            if (a == 1 || total == 1)
                return true;
            if (a < total || total == 0 || a % total == 0)
                return false;
            a %= total;
            total += a;
            pq.push(a);
        }
    }
};




class Solution {
public:
    bool isPossible(vector<int>& t) {
        auto s = accumulate(begin(t), end(t), (long long)0);
        auto i = max_element(begin(t), end(t)) - begin(t);
        while (s > 1 && t[i] > s / 2) {
            s -= t[i];
            if (s <= 1)
                return s;
            t[i] = t[i] % s;
            s += t[i];
            i = max_element(begin(t), end(t)) - begin(t);
        }
        return s == t.size();
    }
};