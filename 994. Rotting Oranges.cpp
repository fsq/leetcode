class Solution {
public:
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    int orangesRotting(vector<vector<int>>& a) {
        queue<pair<int,int>> q;
        int n = a.size(), m = a[0].size(), fresh = 0;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) 
                if (a[i][j]==1) 
                    ++fresh;
                else if (a[i][j]==2)
                    q.push({i, j});
        
        if (!fresh) return 0;
        for (int t=1; q.size(); ++t) {
            for (int x,y,_t=q.size(); _t; --_t) {
                tie(x, y) = q.front();
                q.pop();
                for (int dir=0; dir<4; ++dir) {
                    int tx=x+dx[dir], ty=y+dy[dir];
                    if (tx>=0 && tx<n && ty>=0 && ty<m && a[tx][ty]==1) {
                        if (--fresh==0)
                            return t;
                        a[tx][ty] = 2;
                        q.push({tx, ty});
                    }
                }
            }
        }
        return -1;
    }
};