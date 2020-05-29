class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1, s2;
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s2.push(x);
    }
    
    /*Removes the element from in front of queue and returns that element. */
    int pop() {
        int t = peek();
        s1.pop();
        return t;
    }
    
    /** Get the front element. */
    int peek() {
        if (s1.empty()) {
            while (!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
       return s1.empty() && s2.empty(); 
    }
};
