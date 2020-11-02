class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.size(), m = t.size();
        int ans = 0;
        vector<vector<vector<int>>> f(n+1, vector<vector<int>>(m+1, vector<int>(2, -1)));
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=m; ++j) {
                int x = s[i-1], y = t[j-1];
                if (x==y) {
                    f[i][j][0] = f[i-1][j-1][0]==-1 ? 1 : f[i-1][j-1][0] + 1;
                        
                    if (f[i-1][j-1][1] != -1)
                        f[i][j][1] = f[i-1][j-1][1];
                } else {
                    f[i][j][1] = f[i-1][j-1][0]==-1 ? 1 : f[i-1][j-1][0] + 1;
                }
                if (f[i][j][1]!=-1) ans += f[i][j][1];
            }
        return ans;
    }
};