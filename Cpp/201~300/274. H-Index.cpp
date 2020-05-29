class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int n = citations.size();
        vector<int> buckets(n+1, 0);
        for(int c : citations) {
            if(c >= n) buckets[n]++;
            else buckets[c]++;
        }
        int cnt = 0;
        for (int i = n; i >= 0; i--) {
            cnt += buckets[i];
            if(cnt >= i) return i;
        }
        return 0; 
    }
};