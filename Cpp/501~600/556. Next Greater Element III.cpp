class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if (!next_permutation(s.begin(), s.end())) return -1;
        long long res = stoll(s);
        return res > INT_MAX ? -1 : res; 
    }
};