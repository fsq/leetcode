class FoodRatings {
public:
    unordered_map<string, string> f2c;
    unordered_map<string, int> f2r;
    unordered_map<string, set<pair<int, string>>> rank;

    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        for (int i=0; i<f.size(); ++i) {
            f2c[f[i]] = c[i];
            f2r[f[i]] = r[i];
            rank[c[i]].insert({-r[i], f[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        if (!f2r[food]) return;
        int old = f2r[food];
        f2r[food] = newRating;
        rank[f2c[food]].erase({-old, food});
        rank[f2c[food]].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto& s = rank[cuisine];
        return s.begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */