class Twitter {
public:
    
    priority_queue<pair<int,pair<int,int>>> pq;
    unordered_map<int,unordered_map<int,int>> mp;
    int t=0;

    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        pq.push({t,{userId,tweetId}});
        t++;
    }
    
    vector<int> getNewsFeed(int userId) {
        int k = 10;
        vector<int> ans;
        vector<pair<int,pair<int,int>>> temp;

        while(pq.size() && k>0){
            int t = pq.top().first;
            int id = pq.top().second.first;
            int twt = pq.top().second.second;
            pq.pop();

            if(id == userId || mp[userId][id]){
                ans.push_back(twt);
                k--;
            }
            
            temp.push_back({t,{id,twt}});
        }

        for(auto i: temp) pq.push(i);

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId][followeeId] = 1;
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId][followeeId] = 0;
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