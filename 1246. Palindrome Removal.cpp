class Solution {
public:
    int minimumMoves(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> f(n+1, vector<int>(n+1));
        for (int i=0; i<n; ++i) 
            f[i][i] = 1;
        for (int len=2; len<=n; ++len) 
            for (int i=0; i+len<=n; ++i) {
                int j = i + len - 1;
                f[i][j] = 1 + f[i+1][j];
                for (int k=i+1; k<=j; ++k)
                    if (a[k] == a[i])
                        f[i][j] = min(f[i][j], (i+1==k ? 1 : f[i+1][k-1]) + f[k+1][j]);
            }
        return f[0][n-1];
    }
};