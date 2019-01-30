class TimeMap {
public:
    
    unordered_map<string, vector<pair<int, string>>> map;
    
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!map.count(key)) return "";
        auto& a = map[key];
        auto it = lower_bound(a.begin(), a.end(), pair<int,string>{timestamp+1, ""});
        if (it==a.begin())
            return "";
        else 
            return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */