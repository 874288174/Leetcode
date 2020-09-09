class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<node> pq;
        if (a) pq.emplace('a', a);
        if (b) pq.emplace('b', b);
        if (c) pq.emplace('c', c);
        string res;
        char pre = ' ';
        while (!pq.empty()) {
            stack<node> stk;
            bool ok = false;
            while (!pq.empty()) {
                auto t = pq.top();
                pq.pop();
                if (pre == t.c) {
                    stk.push(t);
                    continue;
                }
                if (stk.empty() && t.x >= 2) {
                    res += string(2, t.c);
                    t.x -= 2;
                }
                else {
                    res += string(1, t.c);
                    t.x -= 1;
                }
                if (t.x > 0) pq.push(t);
                pre = t.c;
                ok = true;
                break;
            }
            if (!ok) break;
            while (!stk.empty()) {
                pq.push(stk.top());
                stk.pop();
            }
        }
        return res;
    }
    struct node {
        node (char c, int x) : c(c), x(x) {};
        char c;
        int x;
        bool operator < (const node &rhs) const {
            if (x != rhs.x) return x < rhs.x;
            else return c < rhs.c;
        }
    };
};




class Solution {
public:
    string longestDiverseString(int a, int b, int c, char aa = 'a', char bb = 'b', char cc = 'c') {
        if (a < b)
            return longestDiverseString(b, a, c, bb, aa, cc);
        if (b < c)
            return longestDiverseString(a, c, b, aa, cc, bb);
        if (b == 0)
            return string(min(2, a), aa);
        auto use_a = min(2, a), use_b = a - use_a >= b ? 1 : 0; 
        return string(use_a, aa) +  string(use_b, bb) + 
            longestDiverseString(a - use_a, b - use_b, c, aa, bb, cc);
    }
};