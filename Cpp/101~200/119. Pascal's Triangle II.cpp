class Solution {
public:
    vector<int> getRow(int rowIndex) {
       vector<int> res(1,1);
       if (rowIndex <= 0) return res;
       for (int i = 0; i < rowIndex; ++i) {
          vector<int> cur;
          cur.push_back(1);
          int sz = res.size();
          for (int i = 1; i < sz; i++) {
              cur.push_back(res[i-1]+res[i]);
          }  
          cur.push_back(1);
          res = cur;
       }
        return res;
    }
};