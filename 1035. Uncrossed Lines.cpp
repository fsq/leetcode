class Solution {
public:
    int maxUncrossedLines(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> f(n, vector<int>(m));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                f[i][j] = max(i>0 ? f[i-1][j] : 0, j>0 ? f[i][j-1] : 0);
                if (a[i] == b[j])
                    f[i][j] = max(f[i][j], ((i==0 || j==0) ? 0:f[i-1][j-1]) + 1);
            }
        }
        return f.back().back();
    }
};