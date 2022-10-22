class Solution {
public:
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> a(n, vector<int>(m));
        for (auto& g : guards) a[g[0]][g[1]] = 1;
        for (auto& w : walls)  a[w[0]][w[1]] = -1;
        for (auto& g : guards) {
            int x = g[0], y = g[1];
            for (int d=0; d<4; ++d) {
                int tx=x+dx[d], ty=y+dy[d];
                while (tx>=0 && tx<n && ty>=0 && ty<m && abs(a[tx][ty])!=1) {
                    a[tx][ty] = 2;
                    tx += dx[d], ty += dy[d];
                }
            }
        }
        int ans = 0;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (a[i][j]==0)
                    ++ans;
        return ans;
    }
};