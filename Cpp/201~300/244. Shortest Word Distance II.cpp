class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            m[words[i]].push_back(i); 
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int> &u = m[word1];  
        vector<int> &v = m[word2];
        int n = u.size(), m = v.size();
        int i = 0, j = 0, dist = INT_MAX;
        while (i < n && j < m) {
            if (u[i] < v[j])  dist = min(dist, v[j]-u[i++]); 
            else  dist = min(dist, u[i]-v[j++]); 
        }
        return dist;
    }
    
private:
    unordered_map<string, vector<int>> m;
};


