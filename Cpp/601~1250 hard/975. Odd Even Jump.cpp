class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size(), res = 1;
        vector<int> index(n);
        iota(index.begin(), index.end(), 0);
        
        auto cmp_odd = [&A](const int x, const int y){
            return A[x] < A[y] || A[x] == A[y] && x < y; 
        };
        auto cmp_even = [&A](const int x, const int y){
            return A[x] > A[y] || A[x] == A[y] && x < y; 
        };
        auto find_next = [n](vector<int>& v) -> vector<int> {
            vector<int> next(n);
            stack<int> stk; 
            for (auto i: v) { 
                while (!stk.empty() && stk.top() < i) {
                    next[stk.top()] = i; 
                    stk.pop(); 
                }
                stk.push(i); 
            }            
            return next; 
        };
        
        sort(index.begin(), index.end(), cmp_odd); 
        vector<int> odd_next = find_next(index); 
        sort(index.begin(), index.end(), cmp_even); 
        vector<int> even_next = find_next(index);
        
        vector<int> odd(n), even(n);
        even[n-1] = odd[n-1] = true; 
        for (int i = n-2; i >= 0; i--) {
            if (odd_next[i]) odd[i] = even[odd_next[i]]; 
            if (even_next[i]) even[i] = odd[even_next[i]];
            if (odd[i]) ++res;
        }
        return res;    
    }
};









class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n  = A.size(), res = 1;
        vector<bool> higher(n), lower(n);
        higher[n - 1] = lower[n - 1] = true;
        map<int, int> mp;
        mp[A[n - 1]] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            auto [hi, lo] = mp.equal_range(A[i]);
            if (hi != mp.end()) higher[i] = lower[hi->second];
            if (lo != mp.begin()) lower[i] = higher[prev(lo)->second];
            if (higher[i]) res++;
            mp[A[i]] = i;
        }
        return res;
    }
};