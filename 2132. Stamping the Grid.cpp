class Solution {
public:
    
    bool empty(vector<vector<int>>& s, int x, int y, int a, int b, bool fit = false) {
        if (!fit && (x<a || y<b)) return false;
        a = max(0, x-a), b = max(0, y-b);
        return s[x][y] - s[a][y] - s[x][b] + s[a][b] == 0;
    }
    
    bool possibleToStamp(vector<vector<int>>& a, int stampHeight, int stampWidth) {
       int n = a.size(), m = a[0].size();
        vector<vector<int>> s(n+1, vector<int>(m+1)), scan=s;
        
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=m; ++j) {
                s[i][j] = a[i-1][j-1] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
                if (empty(s, i, j, stampHeight, stampWidth))
                    scan[i-stampHeight+1][j-stampWidth+1] = 1;
            }
        
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=m; ++j) {
                scan[i][j] = scan[i][j] + scan[i-1][j] + scan[i][j-1] - scan[i-1][j-1];
                if (a[i-1][j-1]==0 && empty(scan, i, j, stampHeight, stampWidth, true)) {
                    return false;
                }
            }
        return true;
    }
};