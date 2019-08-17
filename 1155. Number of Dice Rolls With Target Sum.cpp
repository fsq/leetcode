class Solution {
public:
    
    const int M = 1e9 + 7;
    
    int numRollsToTarget(int n, int m, int target) {
        vector<vector<int>> f(n+1, vector<int>(target+1));
        f[0][0] = 1;
        for (int i=1; i<=n; ++i)
            for (int j=i; j<=min(target, i*m); ++j)
                for (int x=1; x<=m; ++x)
                    if (j >= x)
                        f[i][j] = (f[i][j] + f[i-1][j-x]) % M;
        return f[n][target];
    }
};