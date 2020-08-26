class Solution {
public:
    // Or use Union Set to detect bottom right corner of the loop
    int n, m;
    vector<vector<int>> vis;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    bool bfs(vector<vector<char>>& a, int x, int y) {
        queue<vector<int>> q;
        q.push({x, y, x, y});
        vis[x][y] = true;
        while (q.size()) {
            auto p = q.front(); q.pop();
            int px=p[0], py=p[1], x=p[2], y=p[3];
            for (int dir=0; dir<4; ++dir) {
                int tx = x+dx[dir], ty = y+dy[dir];
                if (tx>=0 && tx<n && ty>=0 && ty<m && a[tx][ty]==a[x][y]) {
                    if (vis[tx][ty] && tx!=px && ty!=py) {
                        return true;
                    }
                    if (!vis[tx][ty]) {
                        q.push({x, y, tx, ty});
                        vis[tx][ty] = true;
                    }
                }
            }
        }
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& a) {
        n = a.size(), m = a[0].size();
        vis = vector<vector<int>>(n, vector<int>(m));
        
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) 
                if (!vis[i][j] && bfs(a, i, j))
                    return true;
        return false;
    }
};