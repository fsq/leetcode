class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), ans = 0;
        vector<vector<int>> f(n, vector<int>(m, INT_MAX));
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) 
                if (a[i][j]) {
                    f[i][j] = min(f[i][j], (i > 0) ? f[i-1][j] : 0);
                    f[i][j] = min(f[i][j], (j > 0) ? f[i][j-1] : 0);
                    f[i][j] = min(f[i][j], (i > 0 && j > 0) ? f[i-1][j-1] : 0);
                    ans += ++f[i][j];
                } else 
                    f[i][j] = 0;
        return ans;
    }
};