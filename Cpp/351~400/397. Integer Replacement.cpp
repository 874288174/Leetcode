class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        else if (n == INT_MAX) return 32;
        if (m.find(n) != m.end()) return m[n];
        if (n % 2 == 0) {
            return m[n] = 1 + integerReplacement(n/2);
        }
        int a = 1 + integerReplacement(n-1);
        int b = 1 + integerReplacement(n+1);
        return m[n] = min(a, b);
    }

private:
    unordered_map<int, int> m;
};