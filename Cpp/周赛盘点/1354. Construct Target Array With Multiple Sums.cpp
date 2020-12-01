//逆推
//设变化后的数组为 s X X X X ,其中s为最大值,和为sum
//则变化而来的数字一定为s,则其他数字之和为sum-s
//又已知变化之前的数字和为s,变化前的数字为s-(sum-s)
//即变化之前的数组为s-(sum-s) X X X X
//即只是将最大的数字减去sum-s即可
//又因为sum-s为其他数字之和,若变化后的数字仍为最大值,只需再减去sum-s即可
//即s = s % (sum-s) 这一步将多次变化合一
//最后sum更新俄为现在的数组和
class Solution {
public:
    bool isPossible(vector<int>& A) {
        long sum = accumulate(A.begin(), A.end(), 0l);
        priority_queue<int> pq(A.begin(), A.end());
        while (1) {
            long s = pq.top(), other = sum-s;
            pq.pop();
            if (s == 1 || other == 1) return true;
            if (s < other || other == 0 || s % other == 0) return false;
            s %= other;
            sum = other + s;
            pq.push(static_cast<int>(s));
        }
    }
};