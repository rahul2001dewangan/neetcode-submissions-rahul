class Twitter {
public:
    int time;

    unordered_map<int, unordered_set<int>> followees;

    unordered_map<int, vector<pair<int, int>>> tweets;

    Twitter() { time = 0; }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        priority_queue<tuple<int, int, int, int>> pq;

        followees[userId].insert(userId);

        for (int u : followees[userId]) {
            auto& v = tweets[u];
            if (!v.empty()) {
                int idx = v.size() - 1;
                pq.push({v[idx].first, v[idx].second, u, idx});
            }
        }

        while (!pq.empty() && res.size() < 10) {
            auto [t, tweetId, u, idx] = pq.top();
            pq.pop();
            res.push_back(tweetId);
            if (idx > 0) {
                idx--;
                pq.push({tweets[u][idx].first, tweets[u][idx].second, u, idx});
            }
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */