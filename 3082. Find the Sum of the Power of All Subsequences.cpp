class Solution {
public:
    const int M = 1000000007;
    long long f[101][101][101]; // first i, sum j, len l

    int sumOfPower(vector<int>& a, int k) {
        memset(f, -1, sizeof(f));
        int n = a.size();
        f[0][0][0] = 1;
        for (int i=1; i<=n; ++i) {
            f[i][0][0] = 1;
            for (int j=0; j<=k; ++j) {
                for (int l=1; l<=n; ++l) {
                    if (f[i-1][j][l] != -1)
                        f[i][j][l] = f[i-1][j][l];
                    if (j>=a[i-1] && f[i-1][j-a[i-1]][l-1] != -1) 
                        f[i][j][l] = ((f[i][j][l]==-1 ? 0 : f[i][j][l]) + f[i-1][j-a[i-1]][l-1]) % M;
                }
            }
        }
        vector<long long> p2 = {1};
        for (int i=1; i<=n; ++i) p2.push_back(p2.back() * 2 % M);
        long long ans = 0;
        for (int l=1; l<=n; ++l)
            if (f[n][k][l] != -1) {
                ans = (ans + f[n][k][l] * p2[n-l]) % M;
            }
        return ans;
    }
};