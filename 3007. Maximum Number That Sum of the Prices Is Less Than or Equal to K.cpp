class Solution {
public:

    long long count(long long x, long long d) {
        long long cur = 0, ans = 0;
        for (long long i=63; i>=0; --i)
            if ((x>>i) & 1) {
                if (i>0) ans += (i/d) * (1ll<<(i-1));
                cur += 1ll << i;
                if ((i+1) % d == 0) {
                    ans += x - cur + 1;
                }
            }
        return ans;
    }

    long long findMaximumNumber(long long k, int x) {
        long long l = 1, r = 1ll<<50;
        while (l < r) {
            long long mid = (l + r + 1) >> 1;
            if (count(mid, x) > k) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return l;
    }
};