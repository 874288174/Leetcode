class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            if (lhs[0] == rhs[0]) return lhs[1] >= rhs[1];
            else return lhs[0] < rhs[0]; 
        });
        int n = people.size();
        vector<int> indices;
        vector<vector<int>> res(n);
        
        for (int i = 0; i < n; ++i) {
            indices.push_back(i);
        }
        
        for (int i = 0; i < n; ++i) {
            int idx = indices[people[i][1]];
            res[indices[people[i][1]]] = people[i];
            indices.erase(indices.begin() + people[i][1]);
        }
        return res;
    }
};

/*
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            if (lhs[0] == rhs[0]) return lhs[1] < rhs[1];
            else return lhs[0] > rhs[0]; 
        });
        vector<vector<int>> res;
        for (const auto &v : people) {
            res.insert(res.begin()+v[1], v);
        }
        return res;     
    }
};
*/