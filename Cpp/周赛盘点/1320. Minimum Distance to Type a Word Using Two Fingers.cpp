class Solution {
public:
    int minimumDistance(string word) {
        map<pair<char, char>, int> pre;
        pre.insert({make_pair(' ', ' '), 0});
        
        for (auto c : word) {
            map<pair<char, char>, int> cur;
            for (auto &it : pre) {
                auto pii = it.first;
                int d = it.second;
                pair<char, char> ss = pii.first < c ? make_pair(pii.first, c) : make_pair(c, pii.first);
                pair<char, char> tt = pii.second < c ? make_pair(pii.second, c) : make_pair(c, pii.second);

                if (cur.count(ss)) 
                    cur[ss] = min(cur[ss], d + dist(pii.second, c));
                else cur[ss] = d + dist(pii.second, c);
                if (cur.count(tt)) 
                    cur[tt] = min(cur[tt], d + dist(pii.first, c));
                else cur[tt] = d + dist(pii.first, c);
            }
            pre = cur;
        }

        int res = INT_MAX;
        for (auto &i : pre) {
            res = min(res, i.second);
        }
        return res;
    }
    
private:
    int dist(char a, char b) {
        if (a == ' ' || b == ' ') return 0;
        int x0 = (a-'A') % 6;
        int y0 = (a-'A') / 6;
        int x1 = (b-'A') % 6;
        int y1 = (b-'A') / 6;
        return abs(x0-x1) + abs(y0-y1);
    }
};



class Solution {
public:
    int minimumDistance(string word) {
        vector<int> dp(26);
        int res = 0, save = 0, n = word.size();
        for (int i = 0; i < n - 1; ++i) {
            int b = word[i] - 'A', c = word[i + 1] - 'A';
            for (int a = 0; a < 26; ++a)
                dp[b] = max(dp[b], dp[a] + d(b, c) - d(a, c));
            save = max(save, dp[b]);
            res += d(b, c);
        }
        return res - save;
    }

    int d(int a, int b) {
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }
};