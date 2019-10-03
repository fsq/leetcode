class Solution {
public:
    int f[103][103][2], n, m;
    
    bool ok(vector<vector<int>>& a, int x, int y) {
        return x>=0 && x<n && y>=0 && y<m && a[x][y]==0;
    }
    
    int minimumMoves(vector<vector<int>>& a) {
        n = a.size(), m = a[0].size();
        
        memset(f, 0xff, sizeof(f));
        f[0][1][0] = 0;
        queue<tuple<int,int,int>> q;
        q.push({0, 1, 0});
        
        for (int tx,ty,x,y,d; !q.empty(); ) {
            tie(x, y, d) = q.front();
            q.pop();
            tx = x, ty = y;
            if (d==0) --ty; else --tx;
            if (ok(a,tx,ty+1) && ok(a,x,y+1) && f[x][y+1][d]==-1) {
                q.push({x, y+1, d});
                f[x][y+1][d] = f[x][y][d] + 1;
                if (x==n-1 && y+1==m-1 && d==0) return f[x][y+1][d];
                if (d==1 && f[tx][ty+1][0]==-1) {
                    q.push({tx, ty+1, 0});
                    f[tx][ty+1][0] = f[x][y][1] + 1;  
                }
            }
            if (ok(a,tx+1,ty) && ok(a,x+1,y) && f[x+1][y][d]==-1) {
                q.push({x+1, y, d});
                f[x+1][y][d] = f[x][y][d] + 1;
                if (x+1==n-1 && y==m-1 && d==0) return f[x+1][y][d];
                if (d==0 && f[tx+1][ty][1]==-1) {
                    q.push({tx+1, ty, 1});
                    f[tx+1][ty][1] = f[x][y][0] + 1;
                }
            }
        }
        return -1;
    }
};