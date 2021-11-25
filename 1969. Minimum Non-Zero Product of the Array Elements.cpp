class Solution {
public:
    
    const int M = 1000000007;
    
    long long pow(long long x, long long y) {
        if (y==0) return 1;
        if (y==1) return x;
        long long s = pow(x, y>>1);
        if (y & 1)
            return s * s % M * x % M;
        else
            return s * s % M;
    }
    
    // split to 1, 11...10, and 11..1
    int minNonZeroProduct(int p) {
        long long s = 1ll<<p; // 2^p
        s = (s - 1 + M) % M; // 1....1
        return pow((s-1+M)%M, (1ll<<(p-1))-1) * s % M;
    }
};
