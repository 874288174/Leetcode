class Solution {
public:
    vector<int> v;
    int sum = 0;
    //c++11 random integer generation
    default_random_engine e;
    uniform_int_distribution<int> uni;

    Solution(vector<int> w) {
        for (int x : w) {
            v.push_back(sum += x);
        }
        uni = uniform_int_distribution<int>{0, sum - 1};
    }

    int pickIndex() {
        int targ = uni(e);
        int low = 0, high = v.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (targ >= v[mid]) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};