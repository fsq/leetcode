class Solution {
public:
    
    int gcd(int x, int y) {
        if (x==0) return y;
        return x>y ? gcd(y, x) : gcd(y%x, x);
    }
    
    bool canMeasureWater(int x, int y, int z) {
        if (x+y < z) return false;
        if (x==z || y==z || x+y==z || z==0) return true;
        int g = gcd(x, y);
        if (g==0) return false;
        return z % g == 0;
    }
};