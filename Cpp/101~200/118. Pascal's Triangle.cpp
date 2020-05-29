class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       if (numRows <= 0) return vector<vector<int>> ();
       vector<vector<int>> res(numRows);
       for (int i = 0; i < numRows; ++i) {
          if (i == 0) {
              res[0].push_back(1);
              continue;
          }
          vector<int> &prev = res[i-1], &cur = res[i];
          cur.push_back(1);
          int sz = prev.size();
          for (int i = 1; i < sz; i++) {
              cur.push_back(prev[i-1]+prev[i]);
          }  
          cur.push_back(1);
       }
        return res;
    }
};