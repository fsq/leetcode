class Solution {
public:
    int n, m;
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    bool out(int x, int y) {
        return !(0<=x && x<n && 0<=y && y<m);
    }
    
    bool dfs(vector<vector<int>>& a, int x, int y) {
        a[x][y] = -1;
        bool touch = false;
        for (int dir=0; dir<4; ++dir) {
            int tx=x+dx[dir], ty=y+dy[dir];
            if (out(tx, ty)) {
                touch = true;
                continue;
            }
            if (!a[tx][ty]) 
                touch |= dfs(a, tx, ty);
        }
        return touch;
    }
    
    int closedIsland(vector<vector<int>>& a) {
        int ans = 0;
        n = a.size(), m = a[0].size();
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (!a[i][j]) 
                    ans += ! dfs(a, i, j);
        return ans;
    }
};