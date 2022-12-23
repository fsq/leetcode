class Solution {
public:
    const int M = 1000000007;

    int countHousePlacements(int n) {
        vector<long long> f(4), g=f;
        f[0] = 1;
        for (int i=0; i<n; ++i) {
            g[0] = (f[0] + f[1] + f[2] + f[3]) % M;
            g[1] = (f[0] + f[2]) % M;
            g[2] = (f[0] + f[1]) % M;
            g[3] = f[0];
            f = g;
        }
        return (f[0] + f[1] + f[2] + f[3]) % M;
    }
};