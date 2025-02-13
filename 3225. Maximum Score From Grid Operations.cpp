class Solution {
public:
    long long lf[102][102][102], rt[102][102][102];
    long long f[102][102];
    int n;

    long long dp(int l, int r) {
        if (f[l][r] != -1) return f[l][r];
        if (l > r) return 0;
        long long& ans = f[l][r];
        for (int d=l; d+1<=r; ++d) {
            ans = max(ans, dp(l, d) + dp(d+1, r));
        }
        for (int i=l; i<=r; ++i)
            ans = max(ans, lf[l][i][n] + rt[r][i][n]);
        return ans;
    }

    // observation1: black areas are disjoint valleys
    // observation2: valley bottoms at last row
    long long maximumScore(vector<vector<int>>& a) {
        n = a.size();
        memset(lf, 0, sizeof(lf)); // f[l][i][j]: from column l, until a[i][j] is valley
        memset(rt, 0, sizeof(rt)); // f[r][i][j]; a[i][j] is valley, until column r
        memset(f, -1, sizeof(f)); // segment col [i, j]
        for (int l=1; l<=n; ++l) {
            for (int i=l; i<=n; ++i) 
                for (int j=1; j<=n; ++j) {
                    int prev = i>l ? a[j-1][i-2] : 0;
                    lf[l][i][j] = max(lf[l][i-1][j], lf[l][i][j-1] + prev);
                }
        }
        for (int r=n; r>=1; --r) {
            for (int i=r; i>=1; --i)
                for (int j=1; j<=n; ++j) {
                    int nxt = i<r ? a[j-1][i] : 0;
                    rt[r][i][j] = max(rt[r][i+1][j], rt[r][i][j-1] + nxt);
                }
        }
        // return dp(1, n);
        for (int len=1; len<=n; ++len) {
            for (int i=1, j=i+len-1; j<=n; ++i, ++j) {
                for (int d=i; d+1<=j; ++d) {
                    f[i][j] = max(f[i][j], f[i][d]+f[d+1][j]); // split into 2
                    f[i][j] = max(f[i][j], lf[i][d][n]+rt[j][d][n]); // or fill with one valley area
                }
                f[i][j] = max(f[i][j], lf[i][j][n]);
            }
        }
        return f[1][n];
    }
};