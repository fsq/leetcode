class Solution {
public:
    
    int f[101][101][21]; // first i, j group, last color k
    int g[101][101][21]; // first i, j group, last color!=k
    
    int minCost(vector<int>& h, vector<vector<int>>& cost, int m, int n, int target) {
        memset(f, 0x3f, sizeof(f));
        memset(g, 0x3f, sizeof(g));
        for (int i=1; i<=n; ++i) f[0][0][i] = g[0][0][i] = 0;
        
        for (int i=1; i<=m; ++i)
            for (int j=1; j<=target; ++j) {
                if (h[i-1]==0) {
                    for (int c=1; c<=n; ++c)
                        f[i][j][c] = min(f[i-1][j][c], g[i-1][j-1][c])+cost[i-1][c-1];   
                } else {
                    f[i][j][h[i-1]] = min(f[i-1][j][h[i-1]], g[i-1][j-1][h[i-1]]);
                }
                
                int m1, m2, id;
                m1 = m2 = 0x3f3f3f3f;
                for (int c=1; c<=n; ++c)
                    if (f[i][j][c]<=m1) {
                        id = c;
                        m2 = m1;
                        m1 = f[i][j][c];
                    } else if (f[i][j][c]<m2)
                        m2 = f[i][j][c];
                for (int c=1; c<=n; ++c)
                    g[i][j][c] = id==c ? m2 : m1;
            }
        int ans = 0x3f3f3f3f;
        for (int c=1; c<=n; ++c)
            ans = min(ans, f[m][target][c]);
        return ans==0x3f3f3f3f ? -1 : ans;
    }
};