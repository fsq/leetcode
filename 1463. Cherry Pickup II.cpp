class Solution {
public:
    
    vector<int> s = {-1, 0, 1};
    int f[72][72][72] = {};
    
    int cherryPickup(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        memset(f, 0x80, sizeof(f));
        f[0][0][m-1] = a[0][0] + a[0].back();
        for (int i=0; i+1<n; ++i) {
            for (int x=0; x<m; ++x)
                for (int y=0; y<m; ++y) 
                    if (f[i][x][y]>=0) {
                        for (int dx=0; dx<3; ++dx) {
                            int tx=x+s[dx];
                            if (tx>=0 && tx<m)
                                for (int dy=0; dy<3; ++dy) {
                                    int ty=y+s[dy];
                                    if (ty>=0 && ty<m) 
                                        f[i+1][tx][ty] = max(f[i+1][tx][ty], 
                                                             f[i][x][y] + (tx==ty ? a[i+1][tx] : a[i+1][tx]+a[i+1][ty]));     
                                }
                        }
                    }
        }
        int ans = 0;
        for (int x=0; x<m; ++x)
            for (int y=0; y<m; ++y)
                ans = max(ans, f[n-1][x][y]);
        return ans;
    }
};