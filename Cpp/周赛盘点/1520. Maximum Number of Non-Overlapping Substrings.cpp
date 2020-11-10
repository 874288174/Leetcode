class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> start(26, INT_MAX), end(26, INT_MIN), skip(26, 0);
        vector<string> result;

        for (int i = 0; i < s.size(); ++i)
            start[s[i] - 'a'] = min(start[s[i] - 'a'], i), end[s[i] - 'a'] = i;

        for (int i = 0; i < 26; ++i)
            for (int j = start[i]; j <= end[i]; ++j)
                if (start[s[j] - 'a'] < start[i]) skip[i] = 1;
                else end[i] = max(end[i], end[s[j] - 'a']);

        for (int i = s.size() - 1, cut = INT_MAX; i >= 0; --i)
            if (i == start[s[i] - 'a'] && end[s[i] - 'a'] < cut && !skip[s[i] - 'a'])
                result.push_back(s.substr((cut = i), end[s[i] - 'a'] - i + 1));

        return result;
    }
};




class Solution {
public:
    int checkSubstr(string &s, int i, vector<int> &l, vector<int> &r) {
        int right = r[s[i] - 'a'];
        for (auto j = i; j <= right; ++j) {
            if (l[s[j] - 'a'] < i)
                return -1;
            right = max(right, r[s[j] - 'a']);
        }
        return right;
    }
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> l(26, INT_MAX), r(26, INT_MIN);
        vector<string> res;
        for (int i = 0; i < s.size(); ++i) {
            l[s[i] - 'a'] = min(l[s[i] - 'a'], i);
            r[s[i] - 'a'] = i;
        }
        int right = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (i == l[s[i] - 'a']) {
                int new_right = checkSubstr(s, i, l, r);
                if (new_right != -1) {
                    if (i > right)
                        res.push_back("");                     
                    right = new_right;
                    res.back() = s.substr(i, right - i + 1);
                }
            }
        }
        return res;
    }
};


