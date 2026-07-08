class Twitter {
private:
    int time = 0;
    
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int,int>>> tweets; // {time, tweetId}

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;

        follows[userId].insert(userId); // ensure self follow

        for (auto followee : follows[userId]) {
            auto &t = tweets[followee];
            if (!t.empty()) {
                int idx = t.size() - 1;
                pq.push({t[idx].first, t[idx].second, followee, idx});
            }
        }

        vector<int> feed;

        while (!pq.empty() && feed.size() < 10) {
            auto top = pq.top(); pq.pop();

            int time = top[0];
            int tweetId = top[1];
            int user = top[2];
            int idx = top[3];

            feed.push_back(tweetId);

            if (idx > 0) {
                pq.push({tweets[user][idx-1].first, tweets[user][idx-1].second, user, idx-1});
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            follows[followerId].erase(followeeId);
    }
};