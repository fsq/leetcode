class Solution {
public:
    int n, m, ans = 0;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    void dfs(vector<vector<int>>& a, vector<vector<int>>& b, int x, int y, bool& ok) {
        if (a[x][y]==0) {
            ok = false;
        }
        b[x][y] = -1;
        for (int dir=0; dir<4; ++dir) {
            int tx=x+dx[dir], ty=y+dy[dir];
            if (tx>=0 && tx<n && ty>=0 && ty<m && b[tx][ty]==1) 
                dfs(a, b, tx, ty, ok);
        }
    }
    
    int countSubIslands(vector<vector<int>>& a, vector<vector<int>>& b) {
        n = a.size();
        m = a[0].size();
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (b[i][j]==1) {
                    bool ok = true;
                    dfs(a, b, i, j, ok);
                    if (ok) ++ans;
                }
        
        return ans;
    }
};