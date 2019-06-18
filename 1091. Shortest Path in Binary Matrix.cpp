class Solution {
public:
    
    vector<int> dx = {-1, -1, -1, 0, 1, 1, 1, 0};
    vector<int> dy = {-1, 0, 1, 1, 1, 0, -1, -1};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        if (a[0][0] || a[n-1][m-1]) return -1;
        vector<vector<int>> vis(n, vector<int>(m));
        queue<pair<int,int>> q;
        q.push({0, 0});
        vis[0][0] = true;
        
        for (int x,y; !q.empty(); q.pop()) {
            tie(x, y) = q.front();
            for (int dir=0; dir<8; ++dir) {
                int tx=x+dx[dir], ty=y+dy[dir];
                if (tx>=0 && tx<n && ty>=0 && ty<m && !a[tx][ty] && !vis[tx][ty]) {
                    vis[tx][ty] = vis[x][y] + 1;
                    if (tx==n-1 && ty==m-1) 
                        return vis[tx][ty];
                    q.push({tx, ty});
                }
            }
        }
        
        return -1;
    }
};