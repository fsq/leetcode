class Solution {
public:
    const int M = 1000000007;

    int numberOfPaths(vector<vector<int>>& a, int k) {
        int n = a.size(), m = a[0].size();
        vector<vector<vector<int>>> f(n, vector<vector<int>>(m, vector<int>(k)));
        f[0][0][a[0][0]%k] = 1;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) 
                for (int t=0; t<k; ++t)
                    if (f[i][j][t]) {
                        if (i+1<n) {
                            f[i+1][j][(t+a[i+1][j])%k] =
                                (f[i+1][j][(t+a[i+1][j])%k] + f[i][j][t]) % M;
                        }
                        if (j+1<m) {
                            f[i][j+1][(t+a[i][j+1])%k] = 
                                (f[i][j+1][(t+a[i][j+1])%k] + f[i][j][t]) % M;
                        }
                    }
        return f[n-1][m-1][0];
    }
};