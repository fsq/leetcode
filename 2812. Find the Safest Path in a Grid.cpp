class Solution {
public:

    vector<vector<int>> d;
    int n;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    bool bfs(vector<vector<int>>& a, int dis) {
        if (d[0][0] < dis) return false;
        queue<pair<int,int>> q;
        vector<vector<int>> vis(a);
        q.push({0, 0});
        a[0][0] = 1;
        while (q.size()) {
            auto p = q.front(); q.pop();
            int x = p.first, y = p.second;
            for (int dir=0; dir<4; ++dir) {
                int tx=x+dx[dir], ty=y+dy[dir];
                if (tx>=0 && tx<n && ty>=0 && ty<n && d[tx][ty]>=dis && !vis[tx][ty]) {
                    if (tx==n-1 && ty==n-1) return true;
                    q.push({tx, ty});
                    vis[tx][ty] = 1;
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& a) {
        n = a.size();
        if (a[0][0]==1 || a[n-1][n-1]==1) return 0;

        queue<pair<int,int>> q;
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (a[i][j]) {
                    q.push({i, j});
                }
        d = a;
        while (q.size()) {
            auto pr = q.front(); q.pop();
            int x = pr.first, y = pr.second;
            for (int dir=0; dir<4; ++dir) {
                int tx = x+dx[dir], ty=y+dy[dir];
                if (tx>=0 && tx<n && ty>=0 && ty<n && d[tx][ty]==0) {
                    d[tx][ty] = d[x][y] + 1;
                    q.push({tx, ty});
                }
            }
        }
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                d[i][j]--;

        int l = 0, r = n;
        while (l < r) {
            int mid = (l+r+1) >> 1;
            int ok = bfs(a, mid);
            if (ok) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};