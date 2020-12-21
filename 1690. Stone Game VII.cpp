class Solution {
public:
    int stoneGameVII(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> f(n, vector<int>(n)), g = f;
        vector<int> s(n);
        partial_sum(a.begin(), a.end(), s.begin());
        for (int len=2; len<=n; ++len) 
            for (int l=0; l+len<=n; ++l) {
                int r = l + len - 1;
                f[l][r] = max(s[r]-s[l] + g[l+1][r], (l==0 ? s[r-1] : s[r-1]-s[l-1]) + g[l][r-1]);
                g[l][r] = min(f[l+1][r] - (s[r]-s[l]), f[l][r-1] - (l==0 ? s[r-1] : s[r-1]-s[l-1]));
            }
        return f[0][n-1];
    }
};