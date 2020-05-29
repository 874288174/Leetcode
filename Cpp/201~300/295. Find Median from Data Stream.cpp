class MedianFinder {
    priority_queue<long> small, large;
public:
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }

    double findMedian() {
        if (small.size() > large.size()) return small.top();
        else return (small.top() - large.top()) / 2.0;
    }
};





class MedianFinder {
    multiset<int> data;
    multiset<int>::iterator mid;

public:
    MedianFinder() {}

    void addNum(int num) {
        const int n = data.size();
        data.insert(num);
        if (!n)                                 // first element inserted
            mid = data.begin();
        else if (num < *mid)                    // median is decreased
            mid = (n & 1 ? prev(mid) : mid);
        else                                    // median is increased
            mid = (n & 1 ? mid : next(mid));
    }

    double findMedian() {
        const int n = data.size();
        return ((double) *mid + *next(mid, (n+1) % 2)) * 0.5;
    }
};