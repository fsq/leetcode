class Solution {
public:
    
    int f[7][7][7][7][244];
    
    int getMaxGridHappiness(int n, int m, int ci, int ce) {
        memset(f, -1, sizeof(f));
        f[0][m-1][ci][ce][0] = 0;
        int ans = 0;
        for (int i=0; i<=n; ++i)
            for (int j=0; j<m; ++j)
                for (int c=0; c<=ci; ++c)
                    for (int e=0; e<=ce; ++e)
                        for (int msk=0; msk<(int)pow(3, m); ++msk) {
                            if (f[i][j][c][e][msk]==-1) continue;
                            ans = max(ans, f[i][j][c][e][msk]);
                            int tx=i, ty=j+1;
                            if (ty==m) ++tx, ty=0;
                            int& empty = f[tx][ty][c][e][msk*3 % (int)pow(3, m)];
                            empty = max(empty, f[i][j][c][e][msk]);
                            
                            vector<int> nei(3);
                            if (ty>0) ++nei[msk % 3];
                            ++nei[msk / (int)pow(3, m-1)];
                            if (c > 0) {
                                int& nxt = f[tx][ty][c-1][e][(msk*3 + 1) % (int)pow(3,m)];
                                nxt = max(nxt,
                                    f[i][j][c][e][msk] + 120 - 30*(nei[1]+nei[2]) - 30*nei[1] + 20*nei[2]);
                            }
                            if (e > 0) {
                                int& nxt = f[tx][ty][c][e-1][(msk*3 + 2) % (int)pow(3,m)];
                                nxt = max(nxt,
                                    f[i][j][c][e][msk] + 40 + 20*(nei[1]+nei[2]) - 30*nei[1] + 20*nei[2]);
                            }
                        }
        return ans;
    }
};