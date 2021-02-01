class MyCalendarThree {
public:
    MyCalendarThree() {}
    map<int, int> mp;

   int book(int start, int end) {
        ++mp[start];
        --mp[end];
        int res = 1, cnt = 0;
        for (auto it : mp) res = max(res, cnt += it.second);
        return res;
    }
};