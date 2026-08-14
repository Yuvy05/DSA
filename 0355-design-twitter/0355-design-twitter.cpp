class Twitter {
public:
    int count ; 
        map<int , vector<pair<int,int>>> tweetMap ;
        map<int , set<int>> followMap ;
    Twitter() {
        count = 0 ;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count , tweetId}) ;
        // check remaining
        count -- ;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res ; // resluting tweet id's
        followMap[userId].insert(userId); //user follows itslef

        // min heap
        // elements in min heap :
        // timestamp,tweetId,userId,//index_of_next_tweet
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> minHeap ; 

        if(followMap.size() >= 10){
            priority_queue<vector<int>>maxHeap ;
            for(auto f : followMap[userId]){
                if(tweetMap.count(f) == 0) continue ;
                int idx = tweetMap[f].size()-1 ;
                auto p = tweetMap[f][idx] ; // pair{count,tweetid}
                maxHeap.push({p.first,p.second,f,idx-1}) ;
                if(maxHeap.size() >10)maxHeap.pop() ;
            }
            while(!maxHeap.empty()){
                auto t = maxHeap.top() ;
                maxHeap.pop() ;
                minHeap.push({t[0],t[1],t[2],t[3]}) ;
            }
        }
        else{
            for(auto user : followMap[userId]){
                if(!tweetMap.count(user)) continue ;// no tweet of that user -> skip for it

                // elements of min heap
                // timestamp,tweetId,userId,index_of_next_tweet

                // put that user's latest tweet in heap
                int idx = tweetMap[user].size()-1 ; //index of the latest tweet
                auto p = tweetMap[user][idx] ;
                minHeap.push({p.first , p.second,user, idx-1}) ;
            }
        }
        while(!minHeap.empty() and res.size()<10){
            // elements of min heap
            // timestamp,tweetId,userId,index_of_next_tweet

            auto latest = minHeap.top() ;//latest element
            minHeap.pop() ;
            res.push_back(latest[1]) ;
            int idx = latest[3] ;
            if(idx >= 0){ // elements present
                auto p = tweetMap[latest[2]][idx] ;
                minHeap.push({p.first , p.second,latest[2],idx-1});
            }
        }
        return res ;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId) ;
    }
    
    void unfollow(int followerId, int followeeId) {
        // check remaining
        followMap[followerId].erase(followeeId) ;
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