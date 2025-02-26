class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    int getFood(vector<vector<char>>& a) {
        queue<pair<int,int>> q;
        int n=a.size(), m=a[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (a[i][j] == '*') {
                    q.push({i, j});
                    vis[i][j] = true;
                    goto bfs;
                }
        bfs:
        for (int step=1; q.size(); ++step) {
            for (int t=q.size(); t; --t) {
                auto [x, y] = q.front(); 
                q.pop();
                for (int d=0; d<4; ++d) {
                    int tx=x+dx[d], ty=y+dy[d];
                    if (tx>=0 && tx<n && ty>=0 && ty<m && a[tx][ty]!='X' && !vis[tx][ty]) {
                        if (a[tx][ty] == '#') {
                            return step;
                        }
                        vis[tx][ty] = true;
                        q.push({tx, ty});
                    }
                }
            }
        }
        return -1;
    }
};