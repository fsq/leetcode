class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        // f[n] = 1/n + 1/n*f[n-1] + 1/n*f[n-2] + ... + 1/n*f[2] or
        // f[n] = 1/n + (n-2)/n * f[n-1]
        return n==1 ? 1 : 0.5;
    }
};