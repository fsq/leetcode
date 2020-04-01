class UndergroundSystem {
public:
    unordered_map<string, unordered_map<string, pair<int,int>>> m;
    unordered_map<int, pair<string, int>> in;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string from = in[id].first;
        int start = in[id].second;
        in.erase(id);
        ++m[from][stationName].first;
        m[from][stationName].second += t-start;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto& pr = m[startStation][endStation];
        return pr.second*1.0 / pr.first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */