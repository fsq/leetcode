class Leaderboard {
public:
    unordered_map<int, int> a;
    vector<int> s;
    Leaderboard() {
    }
    
    void addScore(int id, int score) {
        if (!a.count(id)) 
            s.push_back(id);
            
        a[id] += score;
    }
    
    int top(int K) {
        nth_element(s.begin(), s.begin()+K, s.end(), [&](int x, int y) {
            return a[x] > a[y];  
        });
        return accumulate(s.begin(), s.begin()+K, 0, [&](int sum, int x) {
            return sum + a[x];
        });
    }
    
    void reset(int playerId) {
        a[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */