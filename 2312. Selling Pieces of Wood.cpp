class Solution {
public:
    long long sellingWood(int n, int m, vector<vector<int>>& bs) {
        vector<vector<long long>> f(n+1, vector<long long>(m+1));
        unordered_map<int, unordered_map<int, int>> b;
        for (auto& p : bs) b[p[0]][p[1]] = p[2];

        for (int x=1; x<=n; ++x)
            for (int y=1; y<=m; ++y) {
                long long ans = b[x][y];
                for (int r=1; r<=x/2; ++r) ans = max(ans, f[r][y] + f[x-r][y]);
                for (int c=1; c<=y/2; ++c) ans = max(ans, f[x][c] + f[x][y-c]);
                f[x][y] = ans;
                printf("f[%d][%d]=%lld\n", x, y, f[x][y]);
            }
        return f[n][m];
    }
};