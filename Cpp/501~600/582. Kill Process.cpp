class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> res;
        unordered_map<int , vector<int>> mp;
        for (int i = 0; i < ppid.size(); ++i) {
            mp[ppid[i]].emplace_back(pid[i]);
        }

        stack<int> stk;
        stk.push(kill);
        while (!stk.empty()) {
            int t = stk.top();
            stk.pop();
            res.emplace_back(t);
            if (mp.count(t)) {
                for (auto i : mp[t])
                    stk.push(i);
            }
        }
        return res;
    }
};