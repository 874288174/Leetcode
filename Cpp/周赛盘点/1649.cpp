struct BIT{
    vector<long long> bits;
    BIT(int size) : bits(size+1){}
    
    long long lowbit(long long x) { return x & -x; }
    
    void update(long long i, long long cnt) {
        i++;
        while (i <= bits.size()) {
            bits[i] += cnt;
            i += lowbit(i);
        }
    }
    
    long long query(int i) {
        long long sum = 0;
        while (i > 0) {
            sum += bits[i];
            i -= lowbit(i);
        }
        return sum;
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        long long res = 0, M = 1e9 + 7;
        BIT bit(1e5 + 10);
        for(auto n : instructions) {
            res += min(bit.query(n), bit.query(1e5+1) - bit.query(n+1));
            bit.update(n, 1);
        }
        return res % M;
    }
};