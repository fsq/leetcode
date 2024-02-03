class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> f(n+1, vector<int>(n+1, 0x3f3f3f3f));
        for (int i=1; i+1<=n; ++i) {
            f[i][i+1] = f[i+1][i] = 1;
            f[i][i] = 0;
        }
        f[x][y] = f[y][x] = 1;
        
        for (int k=1; k<=n; ++k)
            for (int i=1; i<=n; ++i)
                for (int j=1; j<=n; ++j)
                    if (i != j)
                        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
        vector<int> ans(n);
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j)
                if (i != j)
                    ++ans[f[i][j]-1];
        return ans;
    }
};