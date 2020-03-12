class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; ++i) {
            unused.insert(i);
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (unused.empty()) return -1;
        int ret = *unused.begin();
        unused.erase(ret);
        used.insert(ret);
        return ret;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return unused.count(number);
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        used.erase(number);
        unused.insert(number);
    }
private:
    unordered_set<int> used, unused;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */