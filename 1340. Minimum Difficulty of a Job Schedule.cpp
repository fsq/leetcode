class Solution {
public:
    int minDifficulty(vector<int>& a, int d) {
        int n = a.size();
        if (n < d) return -1;
        if (n==1) return a[0];
        vector<vector<int>> f(n+1, vector<int>(d+1, INT_MAX));
        f[1][1] = a[0];
        for (int i=2; i<=n; ++i) f[i][1] = max(f[i-1][1], a[i-1]);
        for (int j=2; j<=d; ++j) {
            for (int i=n; i>=j; --i) {
                int mx = 0;
                for (int k=i-1; k>=j-1; --k) {
                    mx = max(mx, a[k]);
                    f[i][j] = min(f[i][j], f[k][j-1] + mx);
                }
            }
        }   
        return f[n][d];
    }
};