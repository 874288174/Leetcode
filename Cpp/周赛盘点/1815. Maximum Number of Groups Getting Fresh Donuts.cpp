class Solution {
public:
    int maxHappyGroups(int b, vector<int>& groups) {
        if (b == 1) return groups.size();
        vector<int> freq0(b), freq(b), w(b);
        for(int i : groups) ++freq0[i % b];

        int msum = 1;
        for(int i = 1; i < b; ++i) msum *= (freq0[i] + 1);
        
        w[1] = 1;
        for(int i = 2; i < b; ++i) w[i] = w[i-1] * (freq0[i-1] + 1);
        vector<int> f(msum, 0);

        for(int fmask = 1; fmask < msum; ++fmask) {
            int last = 0;
            for(int i = 1; i < b; ++i) {
                freq[i] = (fmask / w[i]) % (freq0[i] + 1);
                last = (last + (freq0[i] - freq[i]) * i) % b;
            }
            for (int i = 1; i < b; ++i) {
                if (freq[i]) {
                    f[fmask] = max(f[fmask], f[fmask - w[i]] + (last == 0));
                }
            }
        }
        return f[msum-1] + freq0[0];
    }
};
