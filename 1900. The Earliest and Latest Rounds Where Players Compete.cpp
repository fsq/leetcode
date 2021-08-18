class Solution {
public:
    vector<int> d[30][30][30];
    vector<int> f(int n, int x, int y) {
        if (x+y+1==n) return {1, 1};
        if (d[n][x][y][0] != -1)
            return d[n][x][y];
        int r = n / 2, mx=INT_MIN, mn=INT_MAX;
        for (int i=0; i<(1<<r); ++i) {
            int nx = x, ny = y;
            bool ok = true;
            for (int j=0; j<r; ++j) {
                int go = ((i>>j)&1) ? n-j-1 : j;
                if (go==x || go==y) {
                    ok = false;
                    break;                    
                }
                if (go < x) --nx;
                if (go < y) --ny;
            }
            if (!ok) continue;
            auto ans = f((n+1)/2, nx, ny);
            mx = max(mx, ans[1]+1);
            mn = min(mn, ans[0]+1);
        }
        return d[n][x][y] = {mn, mx};
    }
    
    vector<int> earliestAndLatest(int n, int x, int y) {
        for (int x=0; x<=n; ++x)
            for (int i=0; i<=x; ++i)
                for (int j=0; j<=y; ++j)
                    d[x][i][j] = {-1, -1};
        return f(n, x-1, y-1);
    }
};