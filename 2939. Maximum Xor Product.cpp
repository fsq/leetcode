class Solution {
public:
    const long long M = 1000000007;
    int maximumXorProduct(long long a, long long b, int n) {
        for (long long i=n-1; i>=0; --i) {
            if ((a>>i & 1) ^ (b>>i & 1)) {
                // Always xor to the smallest
                if (a < b) {
                    a |= 1ll << i;
                    b &= ~(1ll << i);
                } else {
                    b |= 1ll << i;
                    a &= ~(1ll << i);
                }
            } else if (!(a>>i & 1)) {
                a |= 1ll << i;
                b |= 1ll << i;
            }
        }
        return (a % M) * (b % M) % M;
    }
};