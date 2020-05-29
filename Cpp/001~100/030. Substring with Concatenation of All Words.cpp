class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.empty() || s.empty()) return res;
        unordered_map<string, int> M0, M1;
        const int N = words[0].length(), M = s.length(), K = words.size();
        for(auto &i : words) M0[i]++;

        for (int i = 0; i < N; i++) {
            int cnt = 0, left = i;
            M1.clear();
            for (int j = i; j+N <= M; j += N){
                string a = s.substr(j, N);
                if (M0.count(a)) {
                   if (++M1[a] <= M0[a]){
                       if (++cnt == K){
                          res.push_back(left);
                          cnt--; M1[ s.substr(left, N) ]--; left += N;
                       }
                   }
                   else{
                       while( s.substr(left, N) != a){ 
                           cnt--; M1[ s.substr(left, N) ]--; left += N;
                       }
                       left += N; M1[a]--;
                   }
                }
                else{
                   M1.clear();
                   left = j+N;
                   cnt = 0;
                }
            }
        }
        return res;
    }
};