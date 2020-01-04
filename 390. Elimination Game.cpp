class Solution {
public:
    int lastRemaining(int n, int d = 0) {
        if (n==1) return 1;
        if (!d || (n&1))
            return 2 * lastRemaining(n/2, !d);
        else 
            return 2 * lastRemaining(n/2, !d) - 1;
        
    }
};