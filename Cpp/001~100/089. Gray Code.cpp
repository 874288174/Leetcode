class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        if (n == 0) return res;
        for(int i = 0; i < n; i++) {
            int bit = 1<<i;
            for(int j = res.size()-1; j >= 0; j--) 
                res.push_back(res[j] | bit);
        }
        return res;
    }
};
