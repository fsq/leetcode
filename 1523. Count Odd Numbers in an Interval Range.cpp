class Solution {
public:
    
    int f(int x) {
        if (x<=0) return 0;
        return (x+1)>>1;
    }
    
    int countOdds(int low, int high) {
        return f(high) - f(low-1);   
    }
};