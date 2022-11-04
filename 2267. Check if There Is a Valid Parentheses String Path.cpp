class Solution {
public:
    int f[101][101][101];
    vector<int> dx={0, -1};
    vector<int> dy={-1, 0};
    
    bool hasValidPath(vector<vector<char>>& a) {
        int n = a.size(), m = a[0].size();
        memset(f, 0, sizeof(f));
        if (a[0][0]==')') return false;
        f[0][0][1]= true;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                for (int k=0; k<=min((n+m-1)/2, i+j+1); ++k) {
                    int c = k + (a[i][j]=='(' ? -1 : 1);
                    if (c < 0 || c > (n+m-1)/2) continue;
                    for (int d=0; d<2; ++d) {
                        int tx=i+dx[d], ty=j+dy[d];
                        if (tx>=0 && tx<n && ty>=0 && ty<m) {
                            f[i][j][k] |= f[tx][ty][c];
                        }
                    }
                }
        return f[n-1][m-1][0];
    }
};