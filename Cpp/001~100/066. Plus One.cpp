class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        for(auto i = digits.rbegin(); i != digits.rend(); i++){
            c += *i;
            *i = c % 10;
            c /= 10;
        }
        if(c) digits.insert(digits.begin(), c);
        return digits;
    }
};