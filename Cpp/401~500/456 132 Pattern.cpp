//O(n^2)
class Solution {
public:
    bool find132pattern(vector<int>& v) {
        int n = v.size();
        for (int i = 0; i < n-2; ++i) {
            int k = INT_MAX;
            for (int j = n-1; j > i; --j) {
                if (v[j] <= v[i]) continue;
                if (v[j] <= k) k = v[j];
                else return true;
            }
        }
        return false;
    }
};



//O(n)
/**
思路
1.如果数组长度小于3，直接返回false（寻找132模式）
2.将每个元素前面的最小值，放入数组min
3.从后往前遍历，首先满足条件 3>1
4.while循环确保条件2>1,只要有2<=1的情况，直接出栈
    stk存放比当前min大的数字，且stk从小到大
    （如果stk不可能放入大的数字，因为这样的话在之前判断中就返回true）
5.只要栈非空，说明同时满足3>1 且2>1，一旦满足2<3，返回true
6.其余情况直接入栈 
*/
class Solution {
public:
    bool find132pattern(vector<int>& v) {
        if (v.size() < 3) return false;
        stack<int> stk;
        vector<int> Min;
        auto ops = [](int x, int y) {return min(x, y);};
        partial_sum(v.begin(), v.end(), back_inserter(Min), ops);
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i] > Min[i]) {
                while (!stk.empty() && stk.top() <= Min[i])
                    stk.pop();
                if (!stk.empty() && stk.top() < v[i])
                    return true;
                stk.push(v[i]);
            }
        }
        return false;
    }
};





class Solution {
public:
    bool find132pattern(vector<int>& v) {
        int third = INT_MIN;
        stack<int> stk; //second, all of it is bigger than Third 
        for (int i = v.size() - 1; i >= 0; --i) {
            if (v[i] < third) return true;
            while (!stk.empty() && stk.top() < v[i]) {
                third = stk.top(); 
                stk.pop();
            }
            stk.push(v[i]);
        }
        return false;
    }
};