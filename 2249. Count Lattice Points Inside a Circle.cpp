class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int mx=0, my=0;
        for (auto& c : circles) {
            mx = max(mx, c[0]+c[2]);
            my = max(my, c[1]+c[2]);
        }
        
        auto inside = [](vector<int>& c, int x, int y) {
            return (c[0]-x)*(c[0]-x) + (c[1]-y)*(c[1]-y) <= c[2]*c[2];
        };
        
        int ans = 0;
        for (int i=0; i<=mx; ++i)
            for (int j=0; j<=my; ++j) {
                for (auto& c : circles)
                    if (inside(c, i, j)) {
                        ++ans;
                        break;
                    }
            }
        return ans;
    }
};