class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = 0, cur = 0, Min_gas = INT_MAX, N = gas.size();
        for (int i = 0; i < N; i++) {
            cur += gas[i]-cost[i];
            if(cur < Min_gas) {
                Min_gas = cur;
                res = (i+1)%N;
            }
        }
        if (cur < 0) return -1;
        else return res;
    }
};