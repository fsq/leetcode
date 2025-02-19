class Solution {
public:
    int vis[301][301][4];
    int done[301][301];

    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    int numberOfCleanRooms(vector<vector<int>>& a) {
        memset(vis, 0, sizeof(vis));
        memset(done, 0, sizeof(done));
        int x = 0, y = 0, d = 0;
        int n = a.size(), m = a[0].size();
        int ans = 0;
        while (!vis[x][y][d]) {
            vis[x][y][d] = true;
            if (!done[x][y]) {
                ++ans;
                done[x][y] = true;
            }
            int tx = x + dx[d];
            int ty = y + dy[d];
            if (tx>=0 && tx<n && ty>=0 && ty<m && a[tx][ty]==0) {
                x = tx, y = ty;
            } else {
                d = (d + 1) % 4;
            }
        }
        return ans;
    }
};