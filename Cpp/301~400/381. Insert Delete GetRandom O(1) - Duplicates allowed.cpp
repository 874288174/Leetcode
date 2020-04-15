class RandomizedCollection {
public:
    RandomizedCollection() {}
    
    bool insert(int val) {
        bool ret = !mp.count(val); 
        mp[val].push_back(nums.size());
        nums.emplace_back(val, mp[val].size()-1);
        return ret;
    }
    
    bool remove(int val) {
        if (!mp.count(val)) return false;
        auto last = nums.back();
        mp[last.first][last.second] = mp[val].back();
        nums[mp[val].back()] = last;
        mp[val].pop_back();
        if (mp[val].empty()) mp.erase(val);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
private:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> mp;
};
