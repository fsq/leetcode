class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& a, int k) {
        int n = a.size(), mx = 0;
        vector<vector<int>> f(n, vector<int>(k+1));
        vector<int> s(n);
        s[0] = mx = a[0];
        for (int i=1; i<n; ++i) {
            s[i] = s[i-1] + a[i];
            mx = max(mx, a[i]);
            f[i][0] = mx*(i+1) - s[i];
            for (int j=1; j<=min(i, k); ++j) {
                f[i][j] = INT_MAX;
                int mxnow = a[i];
                for (int r=i-1; r>=j-1; --r) {
                    mxnow = max(mxnow, a[r+1]);
                    f[i][j] = min(f[i][j], 
                          f[r][j-1]+mxnow*(i-r)-(s[i]-s[r]));
                }
            }
        }
        return f[n-1][k];
    }
};