class Solution {
public:
    int c, n, m;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    void dfs(vector<vector<int>>& a, int x, int y, vector<vector<int>>& vis) {
        vis[x][y] = true;
        bool is_border = x==0 || x==n-1 || y==0 || y==m-1;
        for (int dir=0; dir<4; ++dir) {
            int tx=x+dx[dir], ty=y+dy[dir];
            if (tx>=0 && tx<n && ty>=0 && ty<m)
                if (!vis[tx][ty] && a[tx][ty]==c)
                    dfs(a, tx, ty, vis);
                else if (!vis[tx][ty])
                    is_border = true;
        }
        if (is_border) a[x][y] = -1;
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& a, int r0, int c0, int color) {
        c = a[r0][c0];
        n = a.size(), m = a[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m));
        dfs(a, r0, c0, vis);
        for (int i=0; i<n; ++i) 
            for (int j=0; j<m; ++j)
                if (a[i][j]==-1)
                    a[i][j] = color;
        return a;
    }
};
