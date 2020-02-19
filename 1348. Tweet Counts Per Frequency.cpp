class TweetCounts {
public:
    unordered_map<string, multiset<int>> rc;
    unordered_map<string, int> delta;
    TweetCounts() {
        delta["minute"] = 60;
        delta["hour"] = 60 * 60;
        delta["day"] = 60 * 60 * 24;
    }
    
    void recordTweet(string tweetName, int time) {
        rc[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        const auto& f = rc[tweetName];
        vector<int> ans;
        int d = delta[freq];
        auto it = f.lower_bound(startTime);
        
        for (int now=startTime; now<=endTime; now+=d) {
            int cnt = 0;
            while (it!=f.end() && *it<now+d && *it<=endTime) {
                ++cnt;
                ++it;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */