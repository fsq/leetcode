class Solution {
public:
    int minimumOperations(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> f(m, vector<int>(10, INT_MAX));
        vector<vector<int>> cnt(m, vector<int>(10));
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                ++cnt[j][a[i][j]];
        for (int i=0; i<10; ++i)
            f[0][i] = n - cnt[0][i];
        for (int i=1; i<m; ++i) {
            for (int j=0; j<10; ++j) {
                for (int k=0; k<10; ++k) 
                    if (j != k) {
                        f[i][j] = min(f[i][j], f[i-1][k] + (n - cnt[i][j]));
                    }
            }
        }
        return *min_element(f[m-1].begin(), f[m-1].end());
    }
};