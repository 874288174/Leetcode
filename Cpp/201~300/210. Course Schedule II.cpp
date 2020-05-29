class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &pres) {
        visited.resize(numCourses, 0);
        v.resize(numCourses);
        for (auto &i : pres)   v[i[0]].push_back(i[1]);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && !dfs(i)) 
                return vector<int> ();
        }
        return path;
    }
    
private:
    vector<int> path, visited;
    vector<vector<int>> v;

    bool dfs(int i) {
        visited[i] = -1;
        for (auto &j : v[i]) {
            if (visited[j] == -1) return false;
            else if (!visited[j] && !dfs(j)) return false;
        }
        path.push_back(i);
        visited[i] = 1;
        return true;
    }
}