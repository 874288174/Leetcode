class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {        
        vector<int> row(mat[0]);
        for(int i = 1; i < mat.size(); ++i) {
            vector<int> nr;  // next row
            for(int j = 0; j < mat[i].size(); ++j)                          
                for(auto pathSum : row) 
                    nr.push_back(mat[i][j] + pathSum); // all possible path ends at [i,j] by far                    
                            
            sort(nr.begin(), nr.end());            
            nr.resize( min(k, int(nr.size())) );
            row=move(nr);         
        }        
        return row[k-1];
    }
};









class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> ans = {0};
        int maxSize = k + 1;
        
        for(int i = 0; i < mat.size(); i++){
            // cal
            vector<int> temp;
            for(int j = 0; j < mat[i].size(); j++){
                for(int k = 0; k < ans.size(); k++){
                    temp.push_back(mat[i][j] + ans[k]);
                }
            }
            
            sort(temp.begin(), temp.end());
            
            // update answer
            ans.clear();
            int till = min((int)maxSize, (int)temp.size()); // cut Line
         
            for(int j = 0; j < till; j++){
                ans.push_back(temp[j]);
            }
            
        }
        return ans[k -1];
    }
};