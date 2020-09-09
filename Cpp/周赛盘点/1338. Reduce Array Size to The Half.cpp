class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size() / 2;
        unordered_map<int, int> mp;
        for (auto i : arr) ++mp[i];
        int sum = 0, cnt = 0;
        vector<int> temp;
        for (auto &pii : mp) temp.push_back(pii.second);
        sort (temp.begin(), temp.end(), greater<int>());
        for (auto i : temp) {
            sum += i;
            ++cnt;
            if (sum >= n) return cnt;
        }
        return -1;
    }
};




class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        priority_queue<int> pq;
        for (auto n : arr) ++m[n];
        for (auto &p : m) pq.push(p.second);
        int res = 0, cnt = 0;
        while (cnt * 2 < arr.size()) {
            ++res;
            cnt += pq.top(); pq.pop();
        }
        return res;
    }
};

