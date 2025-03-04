class Solution {
public:
    const int M = 1e9 + 7;

    int f(int n) {
        if (n < 0) return 0;
        if (n == 0) return 1;
        int ans = 0;
        for (int six=0; six*6<=n; ++six) {
            int rem = n - six * 6;
            // can have 0, 1, 2, ... ,rem/2 number of 2s
            ans = (ans + rem/2 + 1) % M;
        }
        return ans;
    }

    int numberOfWays(int n) {
        return (f(n) + f(n-4) + f(n-8)) % M;
    }
};