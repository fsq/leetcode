class Solution {
public:
    vector<vector<int>> f;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int n, m;
    const int M = 1000000007;

    int dfs(vector<vector<int>>& a, int i, int j) {
        if (f[i][j] != 0) return f[i][j];
        f[i][j] = 1;
        for (int d=0; d<4; ++d) {
            int tx=i+dx[d], ty=j+dy[d];
            if (tx>=0 && tx<n && ty>=0 && ty<m && a[tx][ty]>a[i][j]) {
                f[i][j] = (f[i][j] + dfs(a, tx, ty)) % M;
            }
        }
        return f[i][j];
    }

    int countPaths(vector<vector<int>>& a) {
        n = a.size(), m = a[0].size();
        f = vector<vector<int>>(n, vector<int>(m));
        int ans = 0;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                ans = (ans + dfs(a, i, j)) % M;
        return ans;
    }
};