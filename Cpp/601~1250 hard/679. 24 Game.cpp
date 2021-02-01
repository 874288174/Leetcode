double MyAdd(double a, double b) {return a+b;}
auto MySub = std::minus<double>();
struct MyMul {
    double operator () (double a, double b) {
        return a*b;
    }
};
auto MyDiv = [](double a, double b) -> double {return a/b;};
unordered_map<char, function<double(double, double)>> MyOperations{
    {'+', MyAdd}, {'-', MySub}, {'*', MyMul()}, {'/', MyDiv}
};

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
       vector<double> pre(nums.begin(), nums.end());
       return find24(pre, 4);
    }
private:
    bool find24(const vector<double> &pre, int n) {
        if (n == 1) return abs(pre[0] - 24) < 1e-6;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                vector<double> cur;
                for(int k = 0; k < n; ++k) {
                   if (k != i && k != j) cur.push_back(pre[k]);
                }
                for (auto op : string("+-*/")) {
                    if ((op == '+' || op == '*') && i > j) continue;
                    else if (op == '/'  && abs(pre[j]) < 1e-6) continue;
                    cur.push_back(MyOperations[op](pre[i], pre[j]));
                    if (find24(cur, n-1)) return true;
                    cur.pop_back();
                }
            }
        }
        return false;
    }
};