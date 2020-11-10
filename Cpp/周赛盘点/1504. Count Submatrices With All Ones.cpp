//O(n^3)
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int res = 0;
        vector<int> h(m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) { 
                h[j] = mat[i][j] ? (h[j]+1) : 0;
            }
            res += solve(h);
        }
        return res;
    }
    
    
private:
   int solve(const vector<int> &h) { 
       int res = 0;
       for (int i = 0; i < h.size(); ++i) {
           int t = h[i];
           for (int j = i; j >= 0; --j) {
               res += (t = min(h[j], t));
           }
       }
       return res;
   }

    int solve_0(const vector<int> &h) { 
       vector<int> sum(h.size(), 0);
       stack<int> stk;
       for (int i = 0; i < h.size(); ++i) {
           int t = h[i];
           for (int j = i; j >= 0; --j) {
               if (h[j] >= t) sum[i] += t;
               else {
                   sum[i] += sum[j];
                   break;
               }
           }
       }
       return accumulate(sum.begin(), sum.end(), 0);
   }
};






//O(n^2)
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int res = 0;
        vector<int> h(m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) { 
                h[j] = mat[i][j] ? (h[j]+1) : 0;
            }
            res += solve(h);
        }
        return res;
    }
    
    
private:
   int solve(const vector<int> &h) { 
       vector<int> sum(h.size(), 0);
       stack<int> stk;
       for (int i = 0; i < h.size(); ++i) {
           while (!stk.empty() && h[stk.top()] >= h[i]) stk.pop();
           if (stk.empty()) sum[i] = h[i] * (i + 1);
           else {
               sum[i] = sum[stk.top()] + h[i] * (i - stk.top());
           } 
           stk.push(i);
       }
       return accumulate(sum.begin(), sum.end(), 0);
   }
};