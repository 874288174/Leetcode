class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {}
    
    void addNum(int val) {
        if (visited.count(val)) return;
        visited.insert(val);
        auto pos = lower_bound(v.begin(), v.end(), vector<int>{val, val});
        bool ok = false;
        if (pos != v.end() && (*pos)[0] == val+1) {
            (*pos)[0] = val;
            ok = true;
        }
        if (pos != v.begin() && (*prev(pos))[1] == val-1) {
            (*prev(pos))[1] = val;
            ok = true;
        }
        if (!ok) v.insert(pos, vector<int>{val, val});
        else if (pos != v.begin() && pos != v.end()) {
            if ((*prev(pos))[1] == (*pos)[0]) {
                (*prev(pos))[1] = (*pos)[1];
                v.erase(pos);
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        return v;
    }
private:
    unordered_set<int> visited;
    vector<vector<int>> v;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */