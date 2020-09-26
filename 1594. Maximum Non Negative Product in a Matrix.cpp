class Solution {
public:
    int maxProductPath(vector<vector<int>>& a) {
        int n=a.size(), m=a[0].size();
        vector<vector<long long>> f(n, vector<long long>(m)), g(n, vector<long long>(m));
        f[0][0] = g[0][0] = a[0][0];
        for (int i=1; i<n; ++i)
            f[i][0] = g[i][0] = f[i-1][0] * a[i][0];
        for (int j=1; j<m; ++j)
            f[0][j] = g[0][j] = f[0][j-1] * a[0][j];
        for (int i=1; i<n; ++i)
            for (int j=1; j<m; ++j) {
                long long ma = max(f[i-1][j], f[i][j-1]) * a[i][j];
                long long mn = min(g[i-1][j], g[i][j-1]) * a[i][j];
                f[i][j] = max(ma, mn);
                g[i][j] = min(ma, mn);
            }
        int ans = f[n-1][m-1];
        if (ans < 0) return -1;
        cout << ans << endl;
        return ans % 1000000007;
    }
};