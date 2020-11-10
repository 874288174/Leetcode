class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        vector<vector<int>> v(n);
        vector<int> indegree(n, 0);
        unordered_set<int> visit;


        for (auto &t : seqs) {
            for (int i = 0; i < t.size(); ++i) {
                if (t[i] < 1 || t[i] > n) return false;
                visit.insert(t[i]-1);
                if (i != 0) {
                   v[t[i-1]-1].push_back(t[i]-1);
                   ++indegree[t[i]-1];
                }
            }
        } 

        if (visit.size() != n) return false;

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (!indegree[i]) {
                q.push(i);
            }
        }

        vector<int> res;
        while (!q.empty()) {
            if (q.size() != 1) return false;
            int u = q.front();
            q.pop();
            res.push_back(u+1);
            for (auto i : v[u]) {
                if (--indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        return res == org;
    }
};