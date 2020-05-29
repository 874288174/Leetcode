class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            if (lhs[0] == rhs[0]) return lhs[1] < rhs[1];
            else return lhs[0] > rhs[0]; 
        });
        vector<vector<int>> res;
        res.reserve(people.size());
        for (const auto &v : people) {
            res.insert(res.begin()+v[1], v);
        }
        return res;     
    }
};