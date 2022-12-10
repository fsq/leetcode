class Solution {
public:
    int minPathCost(vector<vector<int>>& a, vector<vector<int>>& moveCost) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> f(n, vector<int>(m, INT_MAX));
        for (int i=0; i<m; ++i) f[0][i] = a[0][i];
        for (int i=0; i<n-1; ++i)
            for (int j=0; j<m; ++j) {
                for (int k=0; k<m; ++k)
                    f[i+1][k] = min(f[i+1][k], f[i][j]+moveCost[a[i][j]][k]+a[i+1][k]);
            }
        return *min_element(f[n-1].begin(), f[n-1].end());
    }
};