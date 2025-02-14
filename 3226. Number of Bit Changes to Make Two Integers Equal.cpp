class Solution {
public:
    int minChanges(int n, int k) {
        if ((n&k) != k) return -1;
        return __builtin_popcount(n) - __builtin_popcount(k);
    }
};