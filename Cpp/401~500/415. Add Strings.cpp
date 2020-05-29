class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res;
        int carry = 0, n = num1.length(), m = num2.length();
        int i = 0, j = 0;
        while (i < n || j < m) {
            carry += i < n ? num1[i++]-'0' : 0;
            carry += j < m ? num2[j++]-'0' : 0;
            res += carry % 10 + '0';
            carry /= 10;
        }
        if (carry) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};