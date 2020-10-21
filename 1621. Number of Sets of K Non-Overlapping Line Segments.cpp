class Solution {
public:
    int numberOfSets(int n, int k) {
        const int M = 1e9 + 7;
        vector<vector<long long>> f(n+1, vector<long long>(k+1));
        f[0][0] = 1;
        for (int i=1; i<n; ++i) {
            f[i][0] = 1;
            for (int j=1; j<=min(k, i); ++j) {
                f[i][j] = (f[i-1][j] - (i>=2 ? f[i-2][j] : 0) + f[i-1][j-1] + f[i-1][j] + M) % M;
            }
        }
        return f[n-1][k];
    }
};