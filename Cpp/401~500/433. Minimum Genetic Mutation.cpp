class Solution {
public:
    int minMutation(string start, string end, vector<string> &bank) {
        vector<char> gene{'A', 'T', 'C', 'G'};
        queue<string> q;
        q.push(start);
        int res = 0;
        unordered_set<string> My_set(bank.begin(), bank.end());
        if (!My_set.count(end)) return -1;
        while (!q.empty()) {
            int sz = q.size();
            res++;
            while (sz--) {
                string s = q.front();
                q.pop();
                for (int i = 0; i < 8; i++) {
                    char c = s[i];
                    for (int j = 0; j < 4; j++) {
                        if (gene[j] == c) continue;
                        s[i] = gene[j];
                        auto it = My_set.find(s);
                        if (it != My_set.end()) {
                            if (s == end) return res; 
                            My_set.erase(it);
                            q.push(s);
                        }
                    }
                    s[i] = c;
                }
            }
        }
        return -1;
    }
};