class Solution {
public:
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    vector<vector<int>> highestPeak(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> h(n, vector<int>(m, -1));
        queue<pair<int,int>> q;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (a[i][j] == 1) {
                    q.push({i, j});
                    h[i][j] = 0;
                }
        
        while (q.size()) {
            int x, y;
            tie(x, y) = q.front(), q.pop();
            for (int d=0; d<4; ++d) {
                int tx=x+dx[d], ty=y+dy[d];
                if (tx>=0 && tx<n && ty>=0 && ty<m && h[tx][ty]==-1) {
                    h[tx][ty] = h[x][y] + 1;
                    q.push({tx, ty});
                }
            }
        }
        return h;
    }
};