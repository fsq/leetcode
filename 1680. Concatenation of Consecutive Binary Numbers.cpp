class Solution {
public:
    const int M = 1e9 + 7;

    int concatenatedBinary(int n) {
        long long ans = 0;
        for (int i=1; i<=n; ++i) {
            ans = (ans << (int)(log2(i)+1)) + i;
            ans %= M;
        }
        return ans;
    }
};