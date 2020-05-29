class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        istringstream ss(s);
        while (ss >> s) res++;
        return res;
    }
};