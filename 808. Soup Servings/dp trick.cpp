class Solution {
public:
    double f[501][501];
    bool vis[501][501];
    
    
    
    double soupServings(int n) {
        n = (n + 24) / 25;
        if (n>500) return 1;
        
        f[n][n] = 1;
        
        for (int i=n; i>0; --i)
            for (int j=n; j>0; --j) {
                    f[max(i-4,0)][j] += f[i][j] * 0.25;
                    f[max(i-3,0)][max(j-1,0)] += f[i][j] * 0.25;
                    f[max(i-2,0)][max(j-2,0)] += f[i][j] * 0.25;
                    f[max(i-1,0)][max(j-3,0)] += f[i][j] * 0.25;
                }
        double ans = 0;
        for (int i=1; i<=n; ++i)
            ans += f[i][0];
        ans += 0.5 * f[0][0];
        return 1-ans;
    }
};