class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (My_map.find(key) == My_map.end()) return -1;
        CacheList.splice(CacheList.begin(), CacheList, My_map[key]);
        My_map[key] = CacheList.begin();
        return CacheList.begin()->value;
    }
    
    void put(int key, int value) {
        if(My_map.find(key) == My_map.end()){
            if (My_map.size() == capacity) {
                My_map.erase(CacheList.back().key);
                CacheList. pop_back();
            }
            CacheList.push_front(CacheNode{key, value});
            My_map[key] = CacheList.begin();
        }
        else {
            My_map[key]->value = value;
            CacheList.splice(CacheList.begin(), CacheList, My_map[key]);
            My_map[key] = CacheList.begin();
        }
    }
    
private:
    struct CacheNode{
        int key, value;
        CacheNode(int k, int v):key(k), value(v){}
    };
    int capacity;
    unordered_map<int, list<CacheNode>::iterator> My_map;
    list<CacheNode> CacheList;
};