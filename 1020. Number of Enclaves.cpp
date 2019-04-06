class Solution {
public:
    int n, m;
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    void dfs(vector<vector<int>>& a, int x, int y) {
        if (a[x][y] == 0) return;
        a[x][y] = 0;
        for (int dir=0; dir<4; ++dir) {
            int tx=x+dx[dir], ty=y+dy[dir];
            if (tx>=0 && tx<n && ty>=0 && ty<m && a[tx][ty])
                dfs(a, tx, ty);
        }
    }
    
    int numEnclaves(vector<vector<int>>& a) {
        n = a.size(), m = a[0].size();
        for (int i=0; i<n; ++i) {
            dfs(a, i, 0);
            dfs(a, i, m-1);
        }
        for (int i=0; i<m; ++i) {
            dfs(a, 0, i);
            dfs(a, n-1, i);
        }
        int ans = 0;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                ans += a[i][j];
        return ans;
    }
};