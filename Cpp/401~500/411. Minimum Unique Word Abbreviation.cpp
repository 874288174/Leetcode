class Solution {
public:
   string minAbbreviation(string target, vector<string>& dictionary) {
        int n = target.size(), bound = 1 << n;
        unordered_set<int> dict;
        for (const auto &s : dictionary) if (s.size() == n) {
            int bits = 0, cur = bound >> 1;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != target[i]) bits |= cur;
                cur >>= 1;
            }
            dict.emplace(bits);
        }
        if (dict.empty()) return to_string(target.size());

        int minSize = n, minMask = bound-1;
        auto len = [&](int mask) {
            int cnt = 0, res = 0, temp = n;
            while (temp--) {
                if (mask&1) {
                    if (cnt) ++res;
                    ++res;
                    cnt = 0;
                } 
                else ++cnt;
                mask >>= 1;
            }
            return res + (cnt ? 1 : 0);
        };

        for (int mask = 1; mask < bound; mask++) {
            int sz = len(mask);
            if (sz >= minSize) continue;
            bool ok = true;
            for (auto i : dict) {
                if (!(i&mask)) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            minSize = sz;  minMask = mask;
        }

        ostringstream oss;
        int cur = bound>>1, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (minMask&cur) {
                if (cnt) oss << cnt;
                oss << target[i];
                cnt = 0;
            } 
            else ++cnt;
            cur >>= 1;
        }
        if (cnt) oss << cnt;
        return oss.str();
    }
};