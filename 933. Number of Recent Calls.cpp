class RecentCounter {
public:
    queue<pair<int,int>> q;
    int tot = 0;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        ++tot;
        if (q.size() && q.back().first==t)
            ++q.back().second;
        else
            q.push({t, 1});
        while (q.front().first<t-3000) {
            tot -= q.front().second;
            q.pop();
        }
        return tot;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */