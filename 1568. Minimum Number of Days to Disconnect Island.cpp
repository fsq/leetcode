class Solution {
public:
    
    int n, m;
    int vis[31][31];
    vector<int> px = {-1, 0, 1, 0};
    vector<int> py = {0, 1, 0, -1};
    
    void dfs(vector<vector<int>>& a, int x, int y) {
        vis[x][y] = true;
        for (int dir=0; dir<4; ++dir) {
            int tx = x + px[dir], ty = y + py[dir];
            if (tx>=0 && tx<n && ty>=0 && ty<m && a[tx][ty]==1 && !vis[tx][ty]) {
                dfs(a, tx, ty);
            }
        }
    }
    
    bool disc(vector<vector<int>>& a) {
        memset(vis, 0, sizeof(vis));
        bool done = false;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (a[i][j]==1 && !vis[i][j]) 
                    if (done) return true;
                        else {
                            dfs(a, i, j);
                            done = true;
                        }
        return !done;
    }
    
    int minDays(vector<vector<int>>& a) {
        n = a.size(), m = a[0].size();
        if (disc(a)) return 0;
        
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (a[i][j]==1) {
                    a[i][j] = 0;
                    if (disc(a)) return 1;
                    a[i][j] = 1;
                }
        
        return 2;
    }
};