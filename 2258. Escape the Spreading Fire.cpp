class Solution {
public:
    
    int n, m;
    const int SAFE = 1000000000;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    void bfs1(vector<vector<int>>& a, vector<vector<int>>& f) {
        queue<vector<int>> q;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (a[i][j] == 1) {
                    f[i][j] = 0;
                    q.push({i, j});
                }
        int step = 0;
        while (q.size()) {
            ++step;
            for (int _t=q.size(); _t; --_t) {
                int x = q.front()[0], y = q.front()[1];
                q.pop();
                for (int d=0; d<4; ++d) {
                    int tx=x+dx[d], ty=y+dy[d];
                    if (tx>=0 && tx<n && ty>=0 && ty<m && a[tx][ty]==0) {
                        a[tx][ty] = 1;
                        q.push({tx, ty});
                        f[tx][ty] = step;
                    }
                }
            }
        }
    }
    
    int maximumMinutes(vector<vector<int>>& a) {
        n = a.size(), m = a[0].size();
        vector<vector<int>> fire(n, vector<int>(m, -1));
        bfs1(a, fire);
        vector<vector<int>> f(n, vector<int>(m, -1));
        f[0][0] = fire[0][0]==-1 ? SAFE : fire[0][0];
        queue<vector<int>> q;
        q.push({0, 0});
        int step = 0;
        while (q.size()) {
            ++step;
            for (int _t=q.size(); _t; --_t) {
                int x=q.front()[0], y=q.front()[1]; q.pop();
                for (int d=0; d<4; ++d) {
                    int tx=x+dx[d], ty=y+dy[d];
                    if (tx>=0 && tx<n && ty>=0 && ty<m && a[tx][ty]!=2) {
                        int reach = min(f[x][y], fire[tx][ty]==-1 ? SAFE:  
                                        (fire[tx][ty] - step - (tx==n-1 && ty==m-1 ? 0 : 1)));
                        if (reach > f[tx][ty]) {
                            f[tx][ty] = reach;
                            q.push({tx, ty});
                        }
                    }
                }
            }
        }
        return f[n-1][m-1] < 0 ? -1 : f[n-1][m-1];
    }
};