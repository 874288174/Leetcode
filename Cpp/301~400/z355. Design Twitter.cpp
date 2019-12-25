class Twitter {
public:
    struct cmp {
        template <typename T>
        bool operator() (T const &lhs, T const &rhs) {
            return lhs.first > rhs.first;
        }
    };
    
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        follow(userId, userId);
        twitter[userId].push_back(make_pair(timestamp++, tweetId));
    }
    

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (auto &i : user[userId]) {
            for (auto &pii : twitter[i]) {
                if (!pq.empty()  && pq.top().first > pii.first && pq.size() > 10) break;
                pq.push(pii);
                if (pq.size() > 10) pq.pop();
            }
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        user[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            user[followerId].erase(followeeId);
        }
    }
    
private:
    int timestamp = 0;
    unordered_map<int, unordered_set<int>> user;
    unordered_map<int, vector<pair<int, int>>> twitter;
};