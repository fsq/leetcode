class Solution {
public:
    long long f[51][51][101]; // first i, cost j, max k
    const int M = 1e9 + 7;
    
    int numOfArrays(int n, int m, int k) {
        memset(f, 0, sizeof(f));
        for (int k=1; k<=m; ++k) f[1][1][k] = 1;
        
        // f[i][j][k] = f[i-1][j][k]*k + f[i-1][j-1][1..k-1]
        for (int i=2; i<=n; ++i) 
            for (int j=1; j<=i; ++j) {
                long long pre = 0;
                for (int k=1; k<=m; ++k) {
                    f[i][j][k] = (f[i-1][j][k]*k + pre) % M;
                    pre = (pre + f[i-1][j-1][k]) % M;
                }
            }
        int ans = 0;
        for (int i=1; i<=m; ++i)
            ans = (ans + f[n][k][i]) % M;
        return ans;
    }
};