class Twitter {
public:
    unordered_map<int, unordered_set<int>> FriendList;
    unordered_map<int, vector<pair<int,int>>> Posts;
    int time = 1;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        if (Posts.find(userId) == Posts.end()) {
            Posts[userId] = {};
            FriendList[userId].insert(userId);
        }

        Posts[userId].push_back({tweetId, time++});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        priority_queue<pair<int,int>> pq;

        for (int fri : FriendList[userId]) {
            for (auto &it : Posts[fri]) {
                pq.push({it.second, it.first});   
            }
        }

        int cnt = min((int)pq.size(), 10);

        while (cnt--) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }

    void follow(int followerId, int followeeId) {

        if (Posts.find(followerId) == Posts.end()) {
            Posts[followerId] = {};
            FriendList[followerId].insert(followerId);
        }

        if (Posts.find(followeeId) == Posts.end()) {
            Posts[followeeId] = {};
            FriendList[followeeId].insert(followeeId);
        }

        FriendList[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        if (followerId == followeeId)
            return;

        FriendList[followerId].erase(followeeId);
    }
};