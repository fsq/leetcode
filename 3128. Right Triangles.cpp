class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& a) {
        long long ans = 0;
        int n = a.size(), m = a[0].size();
        vector<long long> r(n), c(m);
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                r[i] += a[i][j];
                c[j] += a[i][j];
            }
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (a[i][j]) {
                    ans += (r[i]-1) * (c[j]-1);
                }
        return ans;
    }
};