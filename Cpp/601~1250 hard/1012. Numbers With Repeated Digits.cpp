class Solution {
public:
    int P(int n, int m) {
        int res = 1;
        while (m--) res *= n--;
        return res;
    }
    
    int numDupDigitsAtMostN(int N) {
        if(N < 10) return 0;
        string str = to_string(N);
        int k = str.size();
        vector<int> noDupRes(k, 0);
        
        int noDupBaseSum = 0;
        for(int i = 0; i < k - 1; i++) {
            noDupBaseSum += 9*P(9, i);
        }
        
        int count[10] = {0};
        bool duplicate = false;
        
        for (int i = 0; i < k; i++) {
            int c = str[i]-'0';
            noDupRes[i] = i == 0 ? 9 : noDupRes[i - 1] * (10 - i);
            if (!duplicate) {
                int diff = 0;
                for (int j = c + 1; j < 10; j++) diff += count[j] == 0;
                noDupRes[i] -= diff;
                count[c]++;
                if (count[c] > 1) duplicate = true;
            }
        }
        return N - (noDupBaseSum + noDupRes[k - 1]);
    }
};