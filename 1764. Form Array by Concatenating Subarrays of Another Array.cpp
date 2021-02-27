class Solution {
public:
    bool canChoose(vector<vector<int>>& g, vector<int>& a) {
        int n = a.size(), m = g.size();
        vector<vector<int>> f(n+1, vector<int>(m+1));
        f[0][0] = true;
        for (int i=1; i<=n; ++i) {
            f[i][0] = true;
            int tl = 0;
            for (int j=1; j<=m && tl+g[j-1].size()<=i; ++j) {
                tl += g[j-1].size();
                f[i][j] = f[i-1][j] || 
                    (f[i-g[j-1].size()][j-1] && equal(g[j-1].begin(), g[j-1].end(), a.begin()+i-g[j-1].size()));
            }
        }
        return f[n][m];
    }
};