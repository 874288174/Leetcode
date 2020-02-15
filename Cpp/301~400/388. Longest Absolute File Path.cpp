class Solution {
public:
    int lengthLongestPath(string input) {
        input += "\n";
        stack<int> stk;
        stk.push(0);
        int res = 0, left = 0, pre = -1;
        while (1) {
            auto pos0 = input.find('\n', left);
            auto pos1 = input.find('.', left);
            if (pos0 == string::npos) break;
            int cur = 0;
            while (input[left] == '\t') {
                cur++;
                left += 1;
            }
            for (int i = cur; i <= pre; i++) stk.pop();
            stk.push((int)pos0-left+stk.top()+1);
            if (pos1 != string::npos && pos1 < pos0) 
                res = max(res, stk.top()-1);
            pre = cur;
            left = pos0 + 1;
        }
        return res;
    }
};