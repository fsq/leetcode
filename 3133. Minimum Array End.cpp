class Solution {
public:
    long long minEnd(long long n, long long x) {
        --n;
        int i=0, j=0;
        while (i<63 && j<63) {
            while (i<63 && (x>>i & 1)) ++i;
            if (n>>j & 1) {
                x |= 1ll << i;
            }
            ++j;
            ++i;
        }
        return x;
    }
};