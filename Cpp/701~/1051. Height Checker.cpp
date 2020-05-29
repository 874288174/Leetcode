class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> Newheights = heights;
        sort(Newheights.begin(), Newheights.end());
        int res = 0, n = Newheights.size();
        for (int i = 0; i < n; i++) {
            if (heights[i] != Newheights[i]) 
                res++;
        }
        return res;
    }
};