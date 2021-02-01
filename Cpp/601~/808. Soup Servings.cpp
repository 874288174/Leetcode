class Solution {
public:
    double soupServings(int N) {
        if (N >= 4000) return 1;
        auto res = f(N, N, 1);
        return res.first + res.second / 2.0;
    }
private:
    map<pair<int, int>, pair<double, double>> mp;
    
    pair<double, double> f(int N, int M, double k) {
        N = max(N, 0);
        M = max(M, 0);
        if (mp.count({N, M})) return mp[{N, M}];
        if (N == 0 && M == 0) return {0, k};
        else if (N == 0) return {k, 0};
        else if (M == 0) return {0, 0};

        auto t0 = f(N-100, M, k/4);
        auto t1 = f(N-75, M-25, k/4);
        auto t2 = f(N-50, M-50, k/4);
        auto t3 = f(N-25, M-75, k/4);
        return mp[{N, M}] = {t0.first + t1.first + t2.first + t3.first, 
                t0.second + t1.second + t2.second  + t3.second};
    }
};