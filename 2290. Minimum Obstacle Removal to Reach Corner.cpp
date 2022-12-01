class Solution {
public:
    
    vector<int> dx={-1, 0, 1, 0};
    vector<int> dy={0, 1, 0, -1};
    
    int minimumObstacles(vector<vector<int>>& a) {
        int n=a.size(), m=a[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        vector<vector<int>> d(n, vector<int>(m, INT_MAX)), vis(n, vector<int>(m));
        d[0][0] = 0;
        q.push({0, 0, 0});
        while (q.size()) {
            auto now = q.top();
            q.pop();
            int x = now[1], y = now[2];
            if (vis[x][y]) continue;
            if (x==n-1 && y==m-1) break;
            vis[x][y] = true;
            for (int dir=0; dir<4; ++dir) {
                int tx=x+dx[dir], ty=y+dy[dir];
                if (tx>=0 && tx<n && ty>=0 && ty<m && !vis[tx][ty]) {
                    int nd = now[0] + a[tx][ty];
                    if (nd < d[tx][ty]) {
                        d[tx][ty] = nd;
                        q.push({nd, tx, ty});
                    }
                }
            }   
        }
        return d[n-1][m-1];
    }
};