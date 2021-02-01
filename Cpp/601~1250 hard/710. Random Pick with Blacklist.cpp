//黑名单向白名单做映射
class Solution {
public:
    unordered_map<int, int> mp;
    int wlen;

    Solution(int n, vector<int> b) {
        wlen = n - b.size();
        
        unordered_set<int> w;
        for (int i = wlen; i < n; i++) w.insert(i);
        for (int x : b) w.erase(x);
        
        auto wi = w.begin();
        for (int x : b)
            if (x < wlen)
                mp[x] = *wi++;
    }

    int pick() {
        int k = rand() % wlen;
        return mp.count(k) ? m[k] : k;
    }
};

//二分
//在B中找到第一个比k大的数字
class Solution {
public:
    int m;
    vector<int> b;
    
    Solution(int N, vector<int> blacklist) {
        m = N - blacklist.size();
        sort(blacklist.begin(), blacklist.end());
        blacklist.push_back(N);
        b = std::move(blacklist);
    }

    int pick() {
        int k = rand() % m;
        
        int lo = 0, hi = b.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (b[mid] - mid <= k) lo = mid + 1;
            else hi = mid;
        }
        return b[lo] - (b[lo] - lo - k);
    }
};
