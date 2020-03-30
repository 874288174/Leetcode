class LFUCache {
private:
    struct LRU {
        LRU(int cnt) : cnt(cnt) {}
        int cnt;
        list<pair<int, int>> myList;
        unordered_map<int, list<pair<int, int>>::iterator> mp;
    };
public:
    LFUCache(int capacity) : capacity(capacity){}
    
    int get(int key) {
        if (!capacity ||!LRUCache.count(key)) return -1;
        auto lru = LRUCache[key], next_lru = next(lru);
        int value = lru->mp[key]->second, cnt = lru->cnt + 1;
        if (next_lru == LRUList.end() || next_lru->cnt != cnt) {
            next_lru = LRUList.emplace(next_lru, cnt);
        }
        deleteKey(key);
        LRUinsertKey(next_lru, key, value);
        return value;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (LRUCache.count(key)) {
            get(key);
            LRUCache[key]->mp[key]->second = value;
            return;
        }
        if (sz++ == capacity) {
            deleteKey(LRUList.front().myList.back().first);
            --sz;
        }
        if (LRUList.front().cnt != 1) {
            LRUList.emplace_front(1);
        }
        LRUinsertKey(LRUList.begin(), key, value);
    }

    void deleteKey(int key) {
        auto lru = LRUCache[key];
        lru->myList.erase(lru->mp[key]);
        lru->mp.erase(key);
        if (lru->myList.empty()) {
            LRUList.erase(lru);
        }
        LRUCache.erase(key);
    }
    
    void LRUinsertKey(list<LRU>::iterator lru, int key, int value) {
         lru->myList.push_front({key, value});
         lru->mp[key] = lru->myList.begin();
         LRUCache[key] = lru;
    }

private:
    int capacity, sz = 0;
    list<LRU> LRUList;
    unordered_map<int, list<LRU>::iterator> LRUCache;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */