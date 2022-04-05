class Solution {
private:
    unordered_map<int, int> vis;
public:
    int integerReplacement(int n) {        
        if (n == 1) return 0; 
        else if (vis.count(n)) return vis[n];
        else if (n & 1) 
            return vis[n] = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
        else 
            return vis[n] = 1 + integerReplacement(n / 2);
    }
};