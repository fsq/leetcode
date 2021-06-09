class SeatManager {
public:
    priority_queue<int, vector<int>, std::greater<int>> q;
    
    SeatManager(int n) {
        for (int i=1; i<=n; ++i) q.push(i);    
    }
    
    int reserve() {
        int ret = q.top();
        q.pop();
        return ret;
    }
    
    void unreserve(int seatNumber) {
        q.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */