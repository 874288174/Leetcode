class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (!n /*|| citations.back() < 1*/) return 0;
        int l = 0, r = n;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (citations[mid] < n-mid) l = mid+1;
            else r = mid;
        }
        return n-l;
    }
};
