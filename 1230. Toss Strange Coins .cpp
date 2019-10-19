class Solution {
public:
    double probabilityOfHeads(vector<double>& a, int target) {
        int n = a.size();
        vector<vector<double>> f(n+1, vector<double>(n+1));
        f[0][0] = 1;
        for (int i=1; i<=n; ++i) {
            f[i][0] = f[i-1][0] * (1-a[i-1]);
            for (int j=1; j<=i; ++j)
                f[i][j] = f[i-1][j] * (1-a[i-1]) + f[i-1][j-1] * a[i-1];
        }
        return f[n][target];
    }
};