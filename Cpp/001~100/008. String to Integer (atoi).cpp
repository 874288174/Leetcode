class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        int sign = 1, n = str.length(), i = str.find_first_not_of(' ');
        if (str[i] == '+' || str[i] == '-') sign = str[i++] == '+' ? 1 : -1;
        
        while (i < n && isdigit(str[i])) {
            res = res * 10 + str[i++]-'0';
            if (res * sign > INT_MAX) return INT_MAX;
            if (res * sign < INT_MIN) return INT_MIN;
        }
    
        return res * sign;
    }
}