class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> v;
    
    DetectSquares() {
        
    }
    
    void add(vector<int> p) {
        ++v[p[0]][p[1]];
    }
    
    int count(vector<int> p) {
        int ans = 0;
        for (auto py : v[p[0]])
            if (py.first != p[1]) {
                int l = abs(py.first - p[1]);
                ans += py.second * v[p[0]+l][p[1]] * v[p[0]+l][py.first];
                ans += py.second * v[p[0]-l][p[1]] * v[p[0]-l][py.first];
            }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */