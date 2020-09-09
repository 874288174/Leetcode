class Solution {
public:
    using ll = long long;
    int findMinFibonacciNumbers(int k) {
        while (v.back() < k) {
            v.push_back(v[v.size()-1] + v[v.size()-2]);
        }
        return f(k);
    }
    
    vector<ll> v{1, 1};
    
    int f(int k) {
        if (k <= 1) return k;
        int pos = upper_bound(v.begin(), v.end(), k) - v.begin();
        return 1 + f(k-v[pos-1]);
    }
};




class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if (k < 2) return k;
        int a = 1, b = 1;
        while (b <= k) {
            swap(a, b);
            b += a;
        }
        return 1 + findMinFibonacciNumbers(k - a);
    }
};