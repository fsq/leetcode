class Solution {
public:
    long long maxNumber(long long n) {
        int i = 63 - __builtin_clzll(n);
        return (1ll<<i) - 1;
    }
};