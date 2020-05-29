class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n > m)  swap(m, n);
        long long res = 1;
        for(int i = 1; i < n; i++)
            res = res*(m++)/i;
        return int(res);
    }
};

/*
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> f(n, 1);
        while (--m) {
            for (int j = n-1; j >= 0; j--) {
                if (j != n-1) f[j] += f[j+1];  
            }
        }
        return f[0];
    }
};
*/