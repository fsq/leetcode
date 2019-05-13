class Solution {
public:
    
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    
    void go(const string& s, int& x, int& y, int& d) {
        for (auto c : s)
            if (c == 'L') 
                d = (d + 3) % 4;
            else if (c == 'R')
                d = (d + 1) % 4;
            else if (c == 'G') {
                x += dx[d];
                y += dy[d];
            }
    }
    
    bool isRobotBounded(string  s) {
        int x = 0, y = 0, d = 0;
        go(s, x, y, d);
        return x==0 && y==0 || d;
    }
};