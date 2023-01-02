class Solution {
public:

    const int M = 1000000007;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        int ans = 0;
        vector<int> f(n+1);
        f[1] = 1;
        for (int i=1; i<=n; ++i) {
            for (int j=i+delay; j<=n && j<i+forget; ++j) {
                f[j] = (f[j] + f[i]) % M;
            }
            if (i+forget>n) {
                ans = (ans + f[i]) % M;
            }
        }
        return ans;
    }
};