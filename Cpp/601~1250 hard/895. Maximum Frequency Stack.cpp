class FreqStack {
public:
    map<int, int> cntCache;
    map<int, stack<int>> group;
    int maxFreq = 0;
    
    FreqStack() {}
    
    void push(int x) {
        int freq = ++cntCache[x];
        if (freq > maxFreq) maxFreq = freq;
        group[freq].push(x);
    }
    
    int pop() {
        int ret = group[maxFreq].top();
        group[maxFreq].pop();
        --cntCache[ret];
        if (group[maxFreq].empty()) {
            group.erase(maxFreq);
            --maxFreq;
        }
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */