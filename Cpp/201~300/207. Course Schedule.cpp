class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> v(numCourses);
        vector<int> visited(numCourses, 0);
        for (auto &i : prerequisites) {
            v[i[0]].push_back(i[1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
               if (!dfs(i, visited, v)) return false;
            }
        }
        return true;
    }
    
private:
    bool dfs(int cur, vector<int> &visited, vector<vector<int>> &v) {
        visited[cur] = -1;
        for (auto &j : v[cur]) {
            if (visited[j] == -1) return false;
            else if (visited[j] == 0 && !dfs(j, visited, v)) return false;
        }
        visited[cur] = 1;
        return true;
    }
};
