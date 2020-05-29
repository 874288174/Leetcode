class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> stk;
        for (auto &i : nums2) {
            while (!stk.empty() && stk.top() < i) {
                m[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        for (auto &i : nums1) {
            if (m.count(i)) i = m[i];
            else i = -1;
        }
        return nums1;
    }
};