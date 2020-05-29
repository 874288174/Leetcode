class HitCounter {
public:
    HitCounter() {
        records.resize(300);
    }
    
    void hit(int timestamp) {
        int idx = timestamp % 300;
        if (records[idx].first != timestamp) records[idx] = {timestamp, 0};
        records[idx].second++;
    }
    
   
    int getHits(int timestamp) {
        int res = 0;
        for (auto &pii : records) {
            if (timestamp - pii.first < 300) {
                res += pii.second;
            }
        }
        return res;
    }
    
private:
    vector<pair<int, int>> records; // time, hit
};

