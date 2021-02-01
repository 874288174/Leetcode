class DinnerPlates {
public:
    int c;
    map<int, vector<int>> notEmpty;
    set<int> notFull;

    DinnerPlates(int capacity) {c = capacity;}

    void push(int val) {
        if (notFull.empty())
            notFull.insert(notEmpty.size());
        notEmpty[*notFull.begin()].push_back(val);
        if (notEmpty[*notFull.begin()].size() == c)
            notFull.erase(notFull.begin());
    }

    int pop() {
        if (notEmpty.empty()) return -1;
        return popAtStack(notEmpty.rbegin()->first);
    }

    int popAtStack(int index) {
        if (!notEmpty.count(index)) return -1;
        int val = notEmpty[index].back();
        notEmpty[index].pop_back();
        notFull.insert(index);
        if (notEmpty[index].empty()) notEmpty.erase(index);
        return val;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */