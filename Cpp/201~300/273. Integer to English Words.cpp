class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string s[3] = {"Billion", "Million", "Thousand"}, res;
        for (int i = 0; i <= 3; i++) {
           int k = pow(10,9-3*i), t = num / k;
           if (t > 0) {
               read(t, res);
               if (i != 3) res += s[i] + ' ';
           }
           num %= k;
        }
        res.erase(prev(res.end()));
        return res;
    }    
private:
    void read(int n, string &res) {
        string a[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", 
                        "Sixty", "Seventy", "Eighty", "Ninety"};
        string b[10] = {"", "One", "Two", "Three", "Four", "Five",
                        "Six", "Seven", "Eight", "Nine"};
        string c[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", 
                        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        if (n/100 > 0)  res += b[n/100] + ' ' +  "Hundred ";
        n %= 100;
        if (n/10 == 1)  res += c[n-10] + ' ';
        else {
            if (n/10) res += a[n/10] + ' ';
            if (n%10) res += b[n%10] + ' ';  
        }     
    }
};