class Solution {
public:
    int brokenCalc(int x, int y) {
        if (y==x) return 0;
        if (y<x) return x - y;
        
        return ((y&1) ? brokenCalc(x, y+1) : brokenCalc(x, y>>1)) + 1;
    }
};