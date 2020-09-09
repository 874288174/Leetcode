class Solution {
public:
    int maxScore(vector<int>& P, int k) {
        int sum = 0, res = INT_MAX, S = 0;
        k = P.size()-k;
        for (int i = 0; i < P.size(); ++i) {
            sum += P[i];
            S += P[i];
            if (i >= k) sum -= P[i-k];
            if (i >= k-1) res = min(res, sum);
        }
        return S - res;
        //return helper(P, 0, P.size()-1, k);
    }
private:
    map<pair<int, int>, int> dp;
    int helper(vector<int>& P, int st, int ed, int k) {
        if (k == 0) return 0;
        if (dp.count({st, ed})) return dp[{st, ed}];
        if (st == ed) return P[st];
        int res = 0;
        res = max(P[st] + helper(P, st+1, ed, k-1), P[ed] + helper(P, st, ed-1, k-1));
        return dp[{st, ed}] = res;
    }
};




class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        // Time Complexity: O(k)
        // Space Complexity: O(1)
        
        int n(cp.size()), left(0), right(0);
        
        for (int i = 0; i < k; ++i) left += cp[i];
        
        int ans(left);
        
        for (int i = 0; i < k; ++i) {
            left -= cp[k - i - 1];
            right += cp[n - i - 1];
            ans = max(ans, left + right);
        }
        
        return ans;
    }
};