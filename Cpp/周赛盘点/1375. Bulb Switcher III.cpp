class Solution {
public:
    int numTimesAllBlue(vector<int>& A) {
        int right = 0, res = 0, n = A.size();
        for (int i = 0; i < n; ++i)
            res += (right = max(right, A[i])) == i + 1;
        return res;
    }
};



class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        set<int> off;
        int n = light.size();
        for (int i = 1; i <= n; ++i) off.insert(i);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            off.erase(light[i]);
            if (off.empty() || *off.begin() == i+2) ++res;
        }
        return res;
    }
};

