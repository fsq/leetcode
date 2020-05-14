class Solution {
public:
    
    int f[51][51][11];
    const int M = 1e9 + 7;
    
    int ways(vector<string>& a, int K) {
        memset(f, 0, sizeof(f));
        int n = a.size(), m = a[0].size();
        vector<vector<int>> s(n+1, vector<int>(m+1));
        for (int i=0; i<n; ++i) 
            for (int j=0; j<m; ++j) {
                s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + (a[i][j]=='A');
            }
        
        auto has = [&](int x1, int y1, int x2, int y2) {
            return s[x2+1][y2+1] - s[x1][y2+1] - s[x2+1][y1] + s[x1][y1] > 0;
        };
        
        for (int i=n-1; i>=0; --i)
            for (int j=m-1; j>=0; --j) {
                if (has(i, j, n-1, m-1)) f[i][j][1] = 1;
                for (int k=2; k<=K; ++k) {
                    for (int r=i; r<n-1; ++r) 
                        if (has(i, j, r, m-1)) f[i][j][k] = (f[i][j][k] + f[r+1][j][k-1]) % M;
                    for (int c=j; c<m-1; ++c)
                        if (has(i, j, n-1, c)) f[i][j][k] = (f[i][j][k] + f[i][c+1][k-1]) % M;
                }
            }
        return f[0][0][K];
                
    }
};