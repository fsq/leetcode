class Solution {
public:
    int C(long long n, long long m) {
        long long ans = 1;
        for (int i=0; i<m; ++i) {
            ans *= n - i;
            ans /= i + 1;
        }
        return ans;
    }

    int waysToReachStair(int k) {
        // 2^x = k+y (y>=0)
        int ans = 0;
        for (long long x=0; ; ++x) {
            long long y = (1ll<<x) - k;
            if (y < 0) continue;
            if (y > x+1) break;
            ans += C(x+1, y);
        }
        return ans;
    }
};