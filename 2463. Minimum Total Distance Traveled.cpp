class Solution {
public:

    long long minimumTotalDistance(vector<int>& a, vector<vector<int>>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int n = a.size(), m = b.size();
        vector<vector<long long>> f(n+1, vector<long long>(m+1, LLONG_MAX));
        fill(f[0].begin(), f[0].end(), 0);
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                if (j > 0) f[i+1][j+1] = f[i+1][j];
                long long dist = 0;
                for (int k=1; k<=min(i+1, b[j][1]); ++k) {
                    dist += abs(a[i-k+1] - b[j][0]);
                    if (f[i-k+1][j] != LLONG_MAX)
                        f[i+1][j+1] = min(f[i+1][j+1], f[i-k+1][j] + dist);
                }
            }
        return f[n][m];
    }
};