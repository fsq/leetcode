class Solution {
public:
    
    int n, m;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    void dfs(vector<vector<int>>& a, vector<int>& area, int x, int y) {
        area[2] = max(area[2], x);
        area[3] = max(area[3], y);
        a[x][y] = -1;
        for (int d=0; d<4; ++d) {
            int tx=x+dx[d], ty=y+dy[d];
            if (tx>=0 && tx<n && ty>=0 && ty<m && a[tx][ty]==1) {
                dfs(a, area, tx, ty);
            }
        }
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& a) {
        vector<vector<int>> ans;
        n = a.size(), m = a[0].size();
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (a[i][j] == 1) {
                    vector<int> area = {i, j, i, j};
                    dfs(a, area, i, j);
                    ans.push_back(area);
                }
        return ans;
    }
};