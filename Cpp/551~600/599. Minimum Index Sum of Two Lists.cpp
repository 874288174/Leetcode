class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        for (int i = 0; i < list1.size(); ++i) mp[list1[i]] = i;
        int sum = INT_MAX;
        vector<string> res;
        for (int i = 0; i < list2.size(); ++i) {
            if (mp.count(list2[i])) {
                int cnt = i + mp[list2[i]];
                if (cnt < sum) {
                    res.clear();
                    res.push_back(list2[i]);
                    sum = cnt;
                }
                else if (cnt == sum) res.push_back(list2[i]);
            }
        }
        return res;
    }
};