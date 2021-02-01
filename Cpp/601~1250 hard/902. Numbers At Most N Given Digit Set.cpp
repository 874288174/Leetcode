class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        string S = to_string(N);
        int len = S.size(), dsize = D.size(), res = 0;
        vector<int> powD(len, 1);
        
        for (int i = 1 ; i < len ; ++i) {
            powD[i] = powD[i-1] * D.size();
            res += powD[i];
        }
        
        for (int i = 0 ; i < len ; ++i) {
            bool hasSameNum = false;
            for (const string &d : D) {
                if (d[0] < S[i]) 
                    res += powD[len-i-1];
                else if (d[0] == S[i]) 
                    hasSameNum = true;
            }
            if (!hasSameNum) return res;
        }               
        return res+1;
    }
};