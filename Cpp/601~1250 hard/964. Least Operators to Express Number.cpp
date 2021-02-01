//以加减来分割
class Solution {
public:
    unordered_map<int, int> mp;
    
    int leastOpsExpressTarget(int x, int y) {
		if (mp.count(y)) return mp[y];
        
        if (x > y) return min(y * 2 - 1, (x - y) * 2);
        if (x == y) return 0;
        
        
        long long sum = x;
        int cnt = 0;
        while (sum < y) {
            ++cnt;
            sum *= x;
        }
        
        if (sum == cnt)  return mp[y] = cnt;
        
        
        int a = INT_MAX, b = INT_MAX;
        // using subtract
        if (sum - y < y) {
            a = leastOpsExpressTarget(x, sum - y) + cnt;  
        }
        // using add
        b = leastOpsExpressTarget(x, y - (sum / x)) + cnt - 1;  
        return mp[y] = min(a, b) + 1;
    }
};








//转化成x进制 pos前一位加法得到  neg前一位减法得到
class Solution {
public:
    int leastOpsExpressTarget(int x, int y) {
        int k = 0, pos, neg;
        while (y > 0) {
            int cur = y % x;
            y /= x;
            if (k == 0) {
                pos = cur * 2;
                neg = (x - cur) * 2;        
            }
            else {
                int pos2 = min(cur * k + pos, (cur + 1) * k + neg);
                int neg2 = min((x - cur) * k + pos, (x - cur - 1) * k + neg);
                pos = pos2, neg = neg2;
            }
            ++k;
        }
        return min(pos, k + neg) - 1;
    }
};