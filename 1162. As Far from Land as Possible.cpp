class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    int maxDistance(vector<vector<int>>& a) {
        queue<pair<int,int>> q;
        int n = a.size(), m = a[0].size();
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (a[i][j] == 1)
                    q.push({i, j});
        if (q.empty()) return -1;
        int ans = 0;
        for (int x,y; !q.empty(); q.pop()) {
            tie(x, y) = q.front();
            for (int dir=0; dir<4; ++dir) {
                int tx=x+dx[dir], ty=y+dy[dir];
                if (tx>=0 && tx<n && ty>=0 && ty<m && a[tx][ty]==0) {
                    a[tx][ty] = a[x][y] + 1;
                    ans = max(a[tx][ty], ans);
                    q.push({tx, ty});
                }
            }
        }
        return ans - 1;
        
    }
};