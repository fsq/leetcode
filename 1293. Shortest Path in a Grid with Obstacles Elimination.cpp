class Solution {
public:
    
    int n, m, N;
    int d[41][41][1601];
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    const int INF = 0x3f3f3f3f;
    
    int shortestPath(vector<vector<int>>& a, int k) {
        n = a.size(), m = a[0].size();
        N = n*m;
        memset(d, 0x3f, sizeof(d));
        
        queue<tuple<int,int,int>> q;
        d[0][0][a[0][0]] = 0;
        q.push({0,0,a[0][0]});
        for (int x,y,s; !q.empty(); q.pop()) {
            tie(x,y,s) = q.front();
            for (int dir=0; dir<4; ++dir) {
                int tx=x+dx[dir], ty=y+dy[dir];
                if (tx>=0 && tx<n && ty>=0 && ty<m && s+a[tx][ty]<=k && d[tx][ty][s+a[tx][ty]]==INF) {
                    int ts = s + a[tx][ty];
                    d[tx][ty][ts] = d[x][y][s] + 1;
                    if (n-1-tx+m-1-ty<=k-ts) return d[tx][ty][ts] + n-1-tx + m-1-ty;
                    q.push({tx,ty,ts});
                }
            }
        }
        int ans = INF;
        for (int i=0; i<=k; ++i) ans = min(ans, d[n-1][m-1][i]);
        return ans==INF? -1 : ans;
    }
};