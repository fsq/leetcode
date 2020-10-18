class Solution {
public:
    
    double dist(int x1, int y1, int x2, int y2) {
        return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
    }
    
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        double mx = -1;
        int ax, ay;
        for (int x=0; x<=50; ++x)
            for (int y=0; y<=50; ++y) {
                int cur = 0;
                for (auto& tw : towers) {
                    double d =  dist(x, y, tw[0], tw[1]);
                    if (d <= radius) cur += (int)(tw[2] / (1+d));
                }
                if (cur > mx) {
                    mx = cur;
                    ax = x, ay = y;
                }
            }
        return {ax, ay};
    }
};

