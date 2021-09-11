class MovieRentingSystem {
public:
    unordered_map<int, set<vector<int>, std::less<vector<int>>>> have; // [movie]->[price, shop]
    set<vector<int>, std::less<vector<int>>> rented;
    unordered_map<int, unordered_map<int, int>> p; // [movie][shop]->price
    
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& mv : entries) {
            have[mv[1]].insert({mv[2], mv[0]});
            p[mv[1]][mv[0]] = mv[2];
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        auto it = have[movie].begin();
        while (ans.size()<5 && it!=have[movie].end()) {
            ans.push_back((*it)[1]);
            ++it;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = p[movie][shop];
        auto it = have[movie].lower_bound({price, shop});
        have[movie].erase(it);
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = p[movie][shop];
        auto it = rented.lower_bound({price, shop, movie});
        rented.erase(it);
        have[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        auto it = rented.begin();
        while (ans.size()<5 && it!=rented.end()) {
            ans.push_back({(*it)[1], (*it)[2]});
            ++it;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */