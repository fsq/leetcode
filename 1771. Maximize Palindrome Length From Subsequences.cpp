class Solution {
public:
    int longestPalindrome(string sa, string sb) {
        string s = sa + sb;
        int n = s.size(), ans = 0;
        vector<vector<int>> f(n, vector<int>(n));
        for (int i=0; i<n; ++i) f[i][i] = 1;
        auto g = f;
        
        for (int l=2; l<=n; ++l)
            for (int x=0; x+l<=n; ++x) {
                int y = x + l - 1;
                g[x][y] = max(g[x+1][y], g[x][y-1]);
                if (s[x]==s[y]) {
                    g[x][y] = max(g[x+1][y-1]+2, g[x][y]);
                    
                    f[x][y] = g[x+1][y-1] + 2;
                    if (x<sa.size() && y>=sa.size())
                        ans = max(ans, f[x][y]);
                }
            }
        return ans;
    }
};