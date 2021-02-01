/*
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        for (char t : tasks)  m[t]++;
        priority_queue<int> pq;
        for (auto it : m) pq.push(it.second);
        
        int res = 0;
        int cycle = n + 1;
        while (!pq.empty()) {
            int time = 0;
            vector<int> tmp;
            for (int i = 0; i < cycle; i++) {
                if (pq.empty()) break;
                tmp.push_back(pq.top());
                pq.pop();
                time++;
            }
            for (int cnt : tmp) {
                if (--cnt) pq.push(cnt);
            }
            res += pq.empty() ? time : cycle;
        }
        return res;
    }
};
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        int cnt = 0;
        for (auto c : tasks) {
            m[c]++;
            cnt = max(cnt, m[c]);
        }
        
        int res = (cnt-1) * (n+1);
        for(auto c : m) if (c.second == cnt) res++;
        return max((int)tasks.size(), res);
    }
};
