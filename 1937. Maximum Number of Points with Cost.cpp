class Solution {
public:
    long long maxPoints(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<long long>> f(n, vector<long long>(m));
        long long ans = 0;
        for (int i=0; i<m; ++i) {
            f[0][i] = a[0][i];
            ans = max<long long>(ans, a[0][i]);
        }
        for (int i=1; i<n; ++i) {
            long long mx = 0;
            for (int j=0; j<m; ++j) {
                f[i][j] = max(mx, f[i-1][j]);
                mx = max(mx, f[i-1][j]) - 1;
            }
            
            mx = 0;
            for (int j=m-1; j>=0; --j) {
                f[i][j] = max(mx, f[i][j]) + a[i][j];
                ans = max(ans, f[i][j]);
                mx = max(mx, f[i-1][j]) - 1;
            }
        }
        return ans;
    }
};