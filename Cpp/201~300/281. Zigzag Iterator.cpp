class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) q.emplace_back(v1.begin(), v1.end());
        if (!v2.empty()) q.emplace_back(v2.begin(), v2.end());
    }
    int next() {
        auto [it, end] = q.front();
        q.pop();
        int res = *it++;
        if (it != end) q.emplace_back(it, end);
        return res;
    }
    bool hasNext() {
        return !q.empty();
    }
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
};