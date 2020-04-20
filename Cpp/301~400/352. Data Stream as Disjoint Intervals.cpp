class SummaryRanges {
public:
    /** Initialize your data structure here. */
    void addNum(int val) {
        if (hash_set.count(val)) return;
        hash_set.insert(val);
        auto it = st.lower_bound({val, val});
        int start = val, end = val;
        if (it != st.begin() && (*prev(it))[1] + 1 == val) --it;
        while (it != st.end() && val+1 >= (*it)[0] && val-1 <= (*it)[1]) {
            start = min(start, (*it)[0]);
            end = max(end, (*it)[1]);
            it = st.erase(it);
        }
        st.insert(vector<int> {start, end});
    }
    
    vector<vector<int>> getIntervals() {
        return vector<vector<int>> (st.begin(), st.end());
    }
private:
    unordered_set<int> hash_set;
    set<vector<int>> st;
};