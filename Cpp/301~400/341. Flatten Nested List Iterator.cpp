/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {   
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        for(int i = n-1; i >= 0; --i) {
            stk.push(nestedList[i]);
        }
    }

    int next() {
        int result = stk.top().getInteger();
        stk.pop();
        return result;
    }


    bool hasNext() {
        while (!stk.empty()) {
            auto cur = stk.top();
            if (cur.isInteger()) return true;
            stk.pop();
            auto &adjs = cur.getList();
            int n = adjs.size();
            for(int i = n-1; i >= 0; --i) stk.push(adjs[i]);
        }
        return false;
    }
private:
    stack<NestedInteger> stk;
};
