class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int w = sizeof(int)*8;
        int cnt[w] = {0};
        for (auto i : nums) {
            for (int j = 0; j < w; j++) {
                cnt[j] += (i >> j) & 1;
                cnt[j] %= 3;
            }
        }
        int res = 0;
        for (int i = 0; i < w; i++) {
            res += (cnt[i] << i);
        }
        return res;
    }
};

////////////////////////////////////////////////////////////

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (auto &x : nums) {
            a = a^x & ~b;
            b = b^x & ~a;
        }
        return a; //唯一一个出现一次的数字
        return b; //唯一一个出现两次的数字
    }
};