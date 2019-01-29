class Solution {
    
    int n, m;
    
    public int encode(int x, int y) { return x*m + y; }
    
    int[] dx = {-1, 0, 1, 0};
    int[] dy = {0, 1, 0, -1};
    
    public int uniquePathsIII(int[][] a) {
        n = a.length;
        m = a[0].length;
        
        int beg = 0, end = 0, full = 0;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                if (a[i][j]!=-1) full |= 1 << encode(i, j);
                if (a[i][j]==1)
                    beg = encode(i, j);
                else if (a[i][j]==2)
                    end = encode(i, j);
            }


        int[][] f = new int[1<<(n*m)][n*m];
        f[1<<beg][beg] = 1;
        for (int s=0; s<(1<<(n*m)); ++s)
            for (int now=0; now<n*m; ++now)
                if (f[s][now]>0) {
                    int x = now/m, y = now%m;
                    for (int dir=0; dir<4; ++dir) {
                        int tx=x+dx[dir], ty=y+dy[dir];
                        if (tx>=0 && tx<n && ty>=0 && ty<m && a[tx][ty]!=-1 && (s>>encode(tx,ty) & 1)==0) {
                            int tar = encode(tx, ty);
                            int ns = s | (1<<tar);
                            if (ns!=full && tar==end) continue;
                            f[ns][tar] += f[s][now];
                        }
                    }
                }
        return f[full][end];
    }

}