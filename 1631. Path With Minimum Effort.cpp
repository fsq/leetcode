class Solution {
public:
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    bool ok(vector<vector<int>>& a, int mxh) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        vis[0][0] = true;
        queue<int> q;
        q.push(0);
        while (q.size()) {
            int p = q.front(); q.pop();
            int x = p / m, y = p % m;
            for (int dir=0; dir<4; ++dir) {
                int tx=x+dx[dir], ty=y+dy[dir];
                if (tx>=0 && tx<n && ty>=0 && ty<m && !vis[tx][ty] && abs(a[x][y]-a[tx][ty])<=mxh) {
                    q.push(tx*m + ty);
                    vis[tx][ty] = true;
                    if (tx==n-1 && ty==m-1) break;
                }
            }
        }
        return vis[n-1][m-1];
    }
    
    int minimumEffortPath(vector<vector<int>>& h) {
        int l = 0, r = 1000000;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (ok(h, mid)) 
                r = mid;
            else 
                l = mid + 1;
        }
        return l;
    }
};