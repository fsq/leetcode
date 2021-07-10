class Solution {
public:
    // f[n,k] = f[n-1, k-1] + (n-1) * f[n-1,k]
    int rearrangeSticks(int n, int k) {
        vector<vector<long long>> f(n+1, vector<long long>(k+1));
        f[1][1] = 1;
        for (int i=2; i<=n; ++i)
            for (int j=1; j<=min(i,k); ++j)
                f[i][j] = (f[i-1][j-1] + (i-1)*f[i-1][j]) % 1000000007;
        return f[n][k];
    }
};