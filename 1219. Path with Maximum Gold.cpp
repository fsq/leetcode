class Solution {
public:
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    int getMaximumGold(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), s=0;
        auto ind = a;
        vector<pair<int,int>> p;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (a[i][j]) {
                    p.push_back({i, j});
                    ind[i][j] = s++;
                }
        
        queue<pair<int,int>> q;
        vector<unordered_map<int,int>> f(s);
        int ans = 0;
        
        for (int i=0; i<s; ++i) {
            q.push({i, 1<<i});
            ans = max(ans, f[i][1<<i] = a[p[i].first][p[i].second]);
        }
        
        for (int x, st; !q.empty(); ) {
            tie(x, st) = q.front(); q.pop();
            for (int dir=0; dir<4; ++dir) {
                int tx=p[x].first+dx[dir], ty=p[x].second+dy[dir];
                if (tx>=0 && tx<n && ty>=0 && ty<m) {
                    int nx = ind[tx][ty];            
                    if (a[tx][ty] && !((st>>nx)&1) && !f[nx].count(st | (1<<nx))) {
                        q.push({nx, st | (1<<nx)});
                        ans = max(ans, f[nx][st | (1<<nx)] = f[x][st] + a[tx][ty]);
                    }
                }
            }
        }
        return ans;
        
        
    }
};