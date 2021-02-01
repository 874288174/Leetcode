class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        auto cmp = [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]); 
        };
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size(), res = 0, p1 = -1, p2 = -1;
        for (const auto &v : intervals) {
            if (v[0] > p2) {
                res += 2;
                p2 = v[1];
                p1 = p2-1;
            }
            else if (v[0] > p1) {
                res++;
                p1 = p2;
                p2 = v[1];
            }
        }
        return res;
    }
};