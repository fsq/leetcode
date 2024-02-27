class Solution {
public:
    int ans = 0;

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    int dfs(vector<vector<int>>& a, int x, int y) {
        int tot = a[x][y];
        a[x][y] = 0;
        for (int d=0; d<4; ++d) {
            int tx=x+dx[d], ty=y+dy[d];
            if (tx>=0 && tx<a.size() && ty>=0 && ty<a[0].size() && a[tx][ty]>0) {
                tot += dfs(a, tx, ty);
            }
        }
        return tot;
    }

    int findMaxFish(vector<vector<int>>& a) {
        for (int i=0; i<a.size(); ++i)
            for (int j=0; j<a[0].size(); ++j)
                if (a[i][j] > 0) {
                    ans = max(ans, dfs(a, i, j));
                }
        return ans;
    }
};