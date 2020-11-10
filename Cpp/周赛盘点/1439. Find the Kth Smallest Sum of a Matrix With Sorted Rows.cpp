class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, size_t k) {        
        vector<int> row{0};
        for(const auto &t : mat) {
            vector<int> v;
            for(const auto &i : t) {                        
                for (const auto &pathSum : row) {
                    v.emplace_back(i + pathSum);
                }       
            }
            partial_sort(v.begin(), v.begin() + min(k, v.size()), v.end());            
            v.resize(min(k, v.size()));
            row = move(v);         
        }        
        return row[k-1];
    }
};
