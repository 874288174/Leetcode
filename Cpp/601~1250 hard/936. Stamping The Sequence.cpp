class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        int cnt = 0, n = stamp.size(), m = target.size();
        while (cnt < m) {
            bool flag = false;
            for (int i = 0; i <= m-n; ++i) {
                int j = 0;
                bool ok = false;
                while (j < n) {
                    if (target[i+j] != stamp[j] && target[i+j] != '?') break;
                    else if (target[i+j] == stamp[j]) ok = true;
                    ++j;
                }
                if (ok && j == n) {
                    for (int j = 0; j < n; ++j) {
                        if (target[i+j] != '?') {
                            target[i+j] = '?';
                            ++cnt;
                        }
                    }
                    res.push_back(i);
                    flag = true;
                }
            }
            if (!flag) break;
        }
        if (cnt != m) return {};
        reverse(res.begin(), res.end());
        return res;
    }
};