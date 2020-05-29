class Solution {
public:
    string intToRoman(int num) {
        string s = "";
        if( num >= 1000 ) s += 'M' + intToRoman(num-1000);
        else if( num >= 900) s = "CM" + s + intToRoman(num-900);
        else if( num >= 500) s += 'D' + intToRoman(num-500);
        else if( num >= 400) s = "CD" + s + intToRoman(num-400);
        else if( num >= 100) s += 'C' + intToRoman(num-100);
        else if( num >= 90) s = "XC" + s + intToRoman(num-90);
        else if( num >= 50) s += 'L' + intToRoman(num-50);
        else if( num >= 40) s = "XL" + s + intToRoman(num-40);
        else if( num >= 10) s += 'X' + intToRoman(num-10);
        else if( num >= 9)  s = "IX" + s + intToRoman(num-9);
        else if( num >= 5) s += 'V' + intToRoman(num-5);
        else if( num >= 4) s = "IV" + s + intToRoman(num-4);
        else if( num >= 1) s += 'I' + intToRoman(num-1);
        return s;
    }
};


////////////////////////////////////////////////////////////
class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> str{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for (int i = 0; i < val.size(); ++i) {
            while (num >= val[i]) {
                num -= val[i];
                res += str[i];
            }
        }
        return res;
    }
};