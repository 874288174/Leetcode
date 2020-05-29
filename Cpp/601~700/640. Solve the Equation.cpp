class Solution {
public:
    string solveEquation(string equation) {
        int pos = equation.find('=');
        auto left = f(equation.substr(0, pos));
        auto right = f(equation.substr(pos+1));
        int cnt = left.first - right.first;
        int val = left.second - right.second;
        if (!cnt && !val) return "Infinite solutions";
        else if (!cnt) return "No solution";
        else return "x=" + to_string(-val/cnt);
    }
    
private:
    pair<int, int> f(string s) {
        s = s + "+";
        int len = s.length();
        pair<int, int> ret{0, 0};
        int sum = 0;
        bool neg;
        for (int i = 0; i < len; ++i) {
            char c = s[i];
            if (c == '+' || c == '-') {
                ret.second += (neg ? -1 : 1) * sum;
                sum = 0;
                neg = (c == '-');
            }
            else if (c == 'x') {
                ret.first += (neg ? -1 : 1) * ((!sum && !isdigit(s[i-1])) ? 1 : sum);
                sum = 0;
            }
            else sum = 10 * sum + c - '0';
        }
        return ret;
    }
};