class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int res = INT_MAX; 
        vector<int> v[2];
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) v[0].push_back(i); 
            if (words[i] == word2) v[1].push_back(i); 
        }
        int n = v[0].size(), m = v[1].size();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (v[0][i] == v[1][j]) i++;
            else if (v[0][i] < v[1][j])  res = min(res, v[1][j]-v[0][i++]); 
            else  res = min(res, v[0][i]-v[1][j++]); 
            
        }
        return res;
    }
};
