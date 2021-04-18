class AuthenticationManager {
public:
    
    multiset<pair<int, string>> st;
    unordered_map<string, int> tk;
    int t;
    
    void pop(int currentTime) {
        while (st.size() && st.begin()->first<=currentTime) {
            tk.erase(st.begin()->second);
            st.erase(st.begin());
        }
    }
    
    AuthenticationManager(int timeToLive) {
        t = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        pop(currentTime);
        tk.insert({tokenId, currentTime+t});
        st.insert({currentTime+t, tokenId});
    }
    
    void renew(string tokenId, int currentTime) {
        pop(currentTime);
        if (!tk.count(tokenId)) return;
        st.erase(st.find({tk[tokenId], tokenId}));
        tk[tokenId] = currentTime+t;
        st.insert({currentTime+t, tokenId});
    }
    
    int countUnexpiredTokens(int currentTime) {
        pop(currentTime);
        return tk.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */