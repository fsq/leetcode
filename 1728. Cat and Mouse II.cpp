class Solution {
public:
    int n, m, fx, fy, cj, mj;
    int f[9][9][9][9][1001][2];
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    bool dfs(const vector<string>& a, int mx, int my, int cx, int cy, int round, int turn) {
        if (mx==cx && my==cy) 
            return false;
        else if (cx==fx && cy==fy)
            return false;
        else if (mx==fx && my==fy) 
            return true;            
        else if (round == n*m*2)
            return false;
        int& ans = f[mx][my][cx][cy][round][turn];
        if (ans != -1) return ans;

        if (turn==0) {
            for (int dir=0; dir<4; ++dir) {
                int tx = mx, ty = my;
                for (int j=0; j<=mj; ++j) {
                    if (tx<0 || tx>=n || ty<0 || ty>=m || a[tx][ty]=='#') break;
                    if (dfs(a, tx, ty, cx, cy, round+1, turn^1)) {
                        ans = 1;
                        goto last;
                    }
                    tx += dx[dir], ty += dy[dir];
                }
            }
            ans = 0;
        } else if (turn==1) {
            for (int dir=0; dir<4; ++dir) {
                int tx = cx, ty = cy;
                for (int j=0; j<=cj; ++j) {
                    if (tx<0 || tx>=n || ty<0 || ty>=m || a[tx][ty]=='#') break;
                    if (!dfs(a, mx, my, tx, ty,round+1, turn^1)) {
                        ans = 0;
                        goto last;
                    }
                    tx += dx[dir], ty += dy[dir];
                }
            }
            ans = 1;
        }
        last:
        return ans;
    }
        
        
    bool canMouseWin(vector<string>& a, int catj, int mouj) {
        int cx, cy, mx, my;
        n = a.size(), m = a[0].size();
        cj = catj, mj = mouj;
        
        memset(f, -1, sizeof(f));
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (a[i][j]=='C')
                    cx = i, cy = j;
                else if (a[i][j]=='M')
                    mx = i, my = j;
                else if (a[i][j]=='F')
                    fx = i, fy = j;
        auto ans = dfs(a, mx, my, cx, cy, 0, 0);
        return ans;
    }
};