class Solution {
public:
    int minimizeXor(int a, int b) {
        int ca = __builtin_popcount(a), cb = __builtin_popcount(b);
        int ans = 0;
        for (int i=31; i>=0 && cb; --i)
            if ((a>>i) & 1) {
                ans ^= 1 << i;
                --cb;
            }
        if (cb) {
            for (int i=0; i<=31 && cb; ++i)
                if (!((ans>>i)&1) && !((a>>i)&1)) {
                    ans ^= 1 << i;
                    --cb;
                }
        }
        return ans;
    }
};