class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {}
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (!mp.count(key)) {
            mp[key] = List.insert(List.begin(), {0, {key}});
        }
        auto next = mp[key], cur = next++;
        if (next == List.end() || next->value > cur->value + 1)
            next = List.insert(next, {cur->value + 1, {}});
        next->keys.insert(key);
        mp[key] = next;
        cur->keys.erase(key);
        if (cur->keys.empty())
            List.erase(cur);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (!mp.count(key)) return;

        auto prev = mp[key], cur = prev--;
        mp.erase(key);
        if (cur->value > 1) {
            if (cur == List.begin() || prev->value < cur->value - 1)
                prev = List.insert(cur, {cur->value - 1, {}});
            prev->keys.insert(key);
            mp[key] = prev;
        }
        
        // Remove the key from its old bucket.
        cur->keys.erase(key);
        if (cur->keys.empty())
            List.erase(cur);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return List.empty() ? "" : *(List.rbegin()->keys.begin());
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return List.empty() ? "" : *(List.begin()->keys.begin());
    }
private:
    struct node {
        int value;
        unordered_set<string> keys;
    };

    list <node> List;
    unordered_map<string, list<node>::iterator> mp;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */