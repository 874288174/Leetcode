class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<bool> bucket(24*60, false);
        for (auto &s : timePoints) {
            int time = stoi(s.substr(0, 2))*60 + stoi(s.substr(3, 2));
            if (bucket[time]) return 0;
            bucket[time] = true;
        }
        int pre = -1, first, res = INT_MAX;
        for (int i = 0; i < 24*60; i++) if (bucket[i]) {
            if (pre == -1) first = pre = i;
            else {
                res = min(res, i-pre);
                pre = i;
            }
        }
        return min(res, first+24*60-pre);
    }
};