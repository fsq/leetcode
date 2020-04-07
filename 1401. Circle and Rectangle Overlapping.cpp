class Solution {
public:
    bool checkOverlap(int r, int cx, int cy, int x1, int y1, int x2, int y2) {
        auto d = [=](int x, int y) {
            return (x-cx)*(x-cx) + (y-cy)*(y-cy);
        };
        
        if (x1<=cx && cx<=x2) {
            if (y1<=cy && cy<=y2) return true;
            return min(abs(y1-cy), abs(y2-cy))<=r;
        } else if (y1<=cy && cy<=y2) {
            return min(abs(x1-cx), abs(x2-cx))<=r;
        } else {
            return min(min(d(x1,y1), d(x1,y2)), min(d(x2,y1),d(x2,y2)))<=r*r;
        }
    }
};