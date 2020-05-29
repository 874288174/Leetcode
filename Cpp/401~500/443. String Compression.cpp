class Solution {
public:
    int compress(vector<char> &chars) {
        chars.push_back('&');
        char pre = chars[0];
        int cnt = 1, res = 0, j = 0, n = chars.size();
        for (int i = 1; i < n; i++){
            if (chars[i] == pre) cnt++;
            else {
                string s = to_string(cnt);
                chars[j++] = pre;
                res += 1 + (cnt == 1 ? 0 : s.length());
                if (cnt != 1) {
                   for (auto &c : s) chars[j++] = c;
                }
                pre = chars[i];
                cnt = 1;
            }
        }
        return res;
    }
};