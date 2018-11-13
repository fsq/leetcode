class Solution {
public:
    int n;
    
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};
    
    void dfs(const vector<vector<int>>& a, vector<vector<int>>& vis, queue<pair<int,int>>& q, int x, int y) {
        vis[x][y] = 1;
        bool border = false;
        for (int dir=0; dir<4; ++dir) {
            int tx=x+dx[dir], ty=y+dy[dir];
            if (tx>=0 && tx<n && ty>=0 && ty<n && !vis[tx][ty])
                if (a[tx][ty]==1)
                    dfs(a, vis, q, tx, ty);
                else
                    border = true;
        }
        if (border) q.push({x, y});
    }
    
    int shortestBridge(vector<vector<int>>& a) {
        n = a.size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(n));
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (a[i][j]) {
                    dfs(a, vis, q, i, j);
                    goto done;
                }
        done:
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            for (int x,y,t=q.size(); t; --t) {
                tie(x,y) = q.front();
                q.pop();
                for (int dir=0; dir<4; ++dir) {
                    int tx=x+dx[dir], ty=y+dy[dir];
                    if (tx>=0 && tx<n && ty>=0 && ty<n && !vis[tx][ty])
                        if (a[tx][ty]==1)
                            return ans-1;
                        else {
                            vis[tx][ty] = 1;
                            q.push({tx, ty});
                        }
                }
            }
        }
        
        return 0;
    }
};