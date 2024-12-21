class Solution {
public:
    int countSubmatrices(vector<vector<int>>& a, int k) {
        int n = a.size(), m = a[0].size(), ans = 0;
        for (int i=1; i<n; ++i) a[i][0] += a[i-1][0];
        for (int i=1; i<m; ++i) a[0][i] += a[0][i-1];
        for (int i=1; i<n; ++i)
            for (int j=1; j<m; ++j) {
                a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            }
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) 
                if (a[i][j] <= k) ++ans;
        }
        return ans;
    }
};