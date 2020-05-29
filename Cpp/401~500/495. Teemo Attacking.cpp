class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int endTime = -1, res = 0;
        for (auto &i : timeSeries) {
            if (i > endTime) {
                res += duration;
                endTime = i + duration;
            }
            else if (i+duration > endTime){
                res += i + duration - endTime;
                endTime = i + duration;
            }
        }
        return res;
    }
};