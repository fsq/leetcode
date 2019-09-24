class Solution {
public:
    
    long long gcd(long long a, long long b) {
        return b==0 ? a : gcd(b, a%b);
    }
    
    long long lcm(long long a, long long b) {
        return a * b / gcd(a, b);
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        long long l = 1, r = 2e9;
        while (l < r) {
            long long m = (l+r) >> 1;
            long long cnt = m/a + m/b + m/c - m/lcm(a, b) - m/lcm(a,c) - m/lcm(b,c) + m/lcm(a,lcm(b,c));
            if (cnt >= n)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};