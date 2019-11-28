class Solution {
public:
    
    const int M = 1e9 + 7;
    
    int numWays(int steps, int n) {
        n = min(n, steps/2+1);
        if (n==1) return 1;
        
        vector<vector<int>> f(steps+1, vector<int>(n));
        f[0][0] = 1;
        for (int i=1; i<=steps; ++i) {
            f[i][0] = (f[i-1][0] + f[i-1][1]) % M;
            f[i][n-1] = (f[i-1][n-2] + f[i-1][n-1]) % M;
            for (int j=1; j<n-1; ++j)
                f[i][j] = ((f[i-1][j] + f[i-1][j-1])%M + f[i-1][j+1]) % M;
        }
        return f[steps][0];
    }
};