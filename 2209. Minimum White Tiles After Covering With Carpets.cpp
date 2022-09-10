class Solution {
public:
    
    int minimumWhiteTiles(string floor, int nc, int carpetLen) {
        int n = floor.size();
        vector<vector<int>> f(n+1, vector<int>(nc+1, n));
        
        fill(f[0].begin(), f[0].end(), 0);
        for (int i=1; i<=n; ++i) {
            f[i][0] = f[i-1][0] + (floor[i-1]=='1');
            for (int j=1; j<=min(nc, i); ++j) {
                f[i][j] = min(f[i-1][j] + (floor[i-1]=='1'), f[max(0, i-carpetLen)][j-1]);
            }
        }
        
        return *min_element(f[n].begin(), f[n].end());
    }
};