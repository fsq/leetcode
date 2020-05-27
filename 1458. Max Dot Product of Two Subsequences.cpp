class Solution {
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> f(n+1, vector<int>(m+1, -500000000));
        int ans = INT_MIN;
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=m; ++j)
                ans = max(ans, f[i][j] = max(max(f[i-1][j], f[i][j-1]), max(f[i-1][j-1]+a[i-1]*b[j-1], a[i-1]*b[j-1])));
        return ans;
    }
};