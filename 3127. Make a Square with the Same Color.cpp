class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& a) {
        for (int x=0; x+1<3; ++x)
            for (int y=0; y+1<3; ++y) {
                int w=0, b=0;
                for (int dx=0; dx<2; ++dx)
                    for (int dy=0; dy<2; ++dy) {
                        int tx=x+dx, ty=y+dy;
                        if (a[tx][ty]=='W') ++w; else ++b;
                    }
                if (w<=1 || b<=1) return true;
            }
        return false;
    }
};