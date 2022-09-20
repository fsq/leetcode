class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& a, int k) {
        int n = a.size();
        for (auto& b : a)
            for (int i=1; i<b.size(); ++i)
                b[i] += b[i-1];
        vector<vector<int>> f(n+1, vector<int>(k+1, 0));
        for (int j=1; j<=k; ++j)
            for (int i=1; i<=n; ++i) {
                f[i][j] = f[i-1][j];
                for (int now=1; now<=min<int>(a[i-1].size(), j); ++now)
                    f[i][j] = max(f[i][j], f[i-1][j-now]+a[i-1][now-1]);
            }
        return f[n][k];
    }
};