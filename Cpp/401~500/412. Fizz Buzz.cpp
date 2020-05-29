class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i++) {
            if (i % 3 != 0 && i % 5 != 0) {
                res.push_back(to_string(i));
            } else if (i % 3 != 0) {
                res.push_back("Buzz");
            } else if (i % 5 != 0) {
                res.push_back("Fizz");
            } else {
                res.push_back("FizzBuzz");
            }
        }
        return res;
    }
};