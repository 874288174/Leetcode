class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        multiset<int> st;
        int res = INT_MAX;
        for (auto i : nums) st.insert(i % 2 ? (2*i) : i);
        while (1) {
            res = min(res, *st.rbegin() - *st.begin());
            int t = *st.rbegin();
            if (t % 2 != 0) break;
            st.erase(prev(st.end()));
            st.insert(t / 2);
        }
        return res;
    }
};