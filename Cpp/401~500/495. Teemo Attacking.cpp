class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        int endTime = timeSeries[0], res = 0;
        for (auto &i : timeSeries) {
            if (i > endTime) {
                res += duration;
                endTime = i + duration;
            }
            else {
                res += i + duration - endTime;
                endTime = i + duration;
            }
        }
        return res;
    }
};
