class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> f2(n, vector<int>(m)), f5 = f2, c2=f2, r2=f2, c5=f5, r5=f5;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                for (int t=a[i][j]; t%2==0; t/=2) ++f2[i][j];
                for (int t=a[i][j]; t%5==0; t/=5) ++f5[i][j];
                r2[i][j] = (j>0 ? r2[i][j-1] : 0) + f2[i][j];
                r5[i][j] = (j>0 ? r5[i][j-1] : 0) + f5[i][j];
                c2[i][j] = (i>0 ? c2[i-1][j] : 0) + f2[i][j];
                c5[i][j] = (i>0 ? c5[i-1][j] : 0) + f5[i][j];
            }
        int ans = 0;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                int left2 = r2[i][j], right2 = r2[i].back() - (j>0 ? r2[i][j-1] : 0);
                int left5 = r5[i][j], right5 = r5[i].back() - (j>0 ? r5[i][j-1] : 0);
                int up2 = c2[i][j]-f2[i][j], down2 = c2[n-1][j] - (i>0 ? c2[i-1][j] : 0) - f2[i][j];
                int up5 = c5[i][j]-f5[i][j], down5 = c5[n-1][j] - (i>0 ? c5[i-1][j] : 0) - f5[i][j];
                ans = max(ans, min(left2+up2, left5+up5));
                ans = max(ans, min(left2+down2, left5+down5));
                ans = max(ans, min(right2+down2, right5+down5));
                ans = max(ans, min(right2+up2, right5+up5));
            }
        return ans;
    }
};