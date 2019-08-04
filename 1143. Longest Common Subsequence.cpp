class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> f(n+1, vector<int>(m+1));
        for (int i=1; i<=n; ++i) 
            for (int j=1; j<=m; ++j)
                if (a[i-1] == b[j-1])
                    f[i][j] = f[i-1][j-1] + 1;
                else 
                    f[i][j] = max(f[i-1][j], f[i][j-1]);
        return f[n][m];
    }
};