class Solution {
public:
    
    const int m = 1000000007;
    
    long long f(long long x, long long y) {
        if (y==0) return 1;
        if (y==1) return x;
        long long s = f(x, y/2);
        if (y & 1) {
            return s * s % m * x % m;
        } else {
            return s * s % m;
        }
    }
    
    int countGoodNumbers(long long n) {
        if (n==1) return 5;
        return f(5, (n+1)/2) * f(4, n/2) % m;
    }
};