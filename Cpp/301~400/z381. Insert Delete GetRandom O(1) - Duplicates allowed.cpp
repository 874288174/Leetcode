//可能还有更好思路
class RandomizedCollection {
public:
    RandomizedCollection() {}
    
    bool insert(int val) {
        bool ret = !mp.count(val); 
        mp[val].push_back(nums.size());
        nums.push_back({val, mp[val].size()-1});
        return ret;
    }
    
    bool remove(int val) {
        if (!mp.count(val)) return false;
        auto last = nums.back();
        auto &delete_ps = mp[val];
        int i = rand() % (int)delete_ps.size();
        int delete_p = mp[val][i];
        if (i != delete_ps.size()-1) {
            delete_ps[i] = delete_ps.back();
        }
        mp[last.first][last.second] = delete_p;
        nums[delete_p] = last;
        delete_ps.pop_back();
        if (delete_ps.empty()) mp.erase(val);
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