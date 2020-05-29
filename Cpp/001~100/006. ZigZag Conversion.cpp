class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int n = s.length();
        string res;
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < n; j += 2*numRows-2) {
                res += s[j];
                if (i == 0 || i == numRows-1) continue;
                if (j+2*(numRows-i-1) < n)  res += s[j+2*(numRows-i-1)];
            }  
        }
        return res;
    }
};
