class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    void push(int x) {
        if (Min_S.empty()) Min_S.push(x);
        else Min_S.push( min(Min_S.top(), x) );
        S.push(x);
    }
    
    void pop() {
        S.pop();
        Min_S.pop();
    }
    
    int top() {
        return S.top();}
    
    int getMin() {
        return Min_S.top();
    }
    
    private:
       stack<int> S, Min_S;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */