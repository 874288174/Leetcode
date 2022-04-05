class Solution {
   public:
    /**
     * 讨论结果的可能性: 对于数字s, 离它最近的回文数字只可能是以下5个中的一个,
     * - (long long)pow(10, n) + 1,      /// 10...01 or 11
     * - (long long)pow(10, n - 1) - 1,  // 9...9 or 0
     * - 前半部分-1 + 前半部分-1翻转
     * - 前半部分   + 前半部分翻转
     * - 前半部分+1 + 前半部分+1翻转
     * 注意: 对于后3种情况, 当长度n为奇数时, 翻转时不要中间位
     */
    using ll = long long;

    string nearestPalindromic(string s) {
        int n = s.length();
        // 前两种情况
        vector<ll> candidates = {
            (ll) pow(10, n) + 1,      // 10...01 or 11
            (ll) pow(10, n - 1) - 1,  // 9...9 or 0
        };
        // 后三种情况
        ll prefix = stol(s.substr(0, (n + 1) / 2));
        for (int i : {-1, 0, 1}) {
            string p = to_string(prefix + i);
            string pp = p + string(p.rbegin() + (n & 1), p.rend());
            candidates.push_back(stoll(pp));
        }
        // 找出与slef差距最小且本身最小且不是self的值
        ll self = stoll(s);
        auto cmp = [&self](auto e1, auto e2) -> bool {
            if (e1 == self) return false;
            if (e2 == self) return true;
            if (abs(self - e1) == abs(self - e2)) return e1 < e2;
            return abs(self - e1) < abs(self - e2);
        };
        return to_string(*min_element(candidates.begin(), candidates.end(), cmp));
    }
};
