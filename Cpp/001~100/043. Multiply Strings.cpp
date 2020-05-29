class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n = num1.size(), m = num2.size();
        vector<int> sum(n+m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                sum[n+m-i-j-2] += (num1[i]-'0')*(num2[j]-'0');
            }
        }
        int carry = 0;
        string res;
        for(int i = 0; i < n+m-1; i++) {
            carry += sum[i];
            res += carry%10+'0';
            carry /= 10;
        }
        if(carry) res += carry+'0';
        reverse(res.begin(), res.end());
        return res;
    }
};