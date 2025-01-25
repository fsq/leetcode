class Solution {
public:

    int f[501][26];

    int maximumLength(vector<int>& a, int k) {
        int n = a.size();
        memset(f, -1, sizeof(f));
        int ans = -1;
        for (int j=0; j<=k; ++j) {
            for (int i=1; i<=n; ++i) {
                f[i][j] = f[i-1][j];
                int cnt = 0;
                for (int t=i; t>=1; --t) {
                    cnt += a[t-1] == a[i-1];
                    if (j == 0) {
                        f[i][j] = max(f[i][j], cnt);
                    } else if (f[t-1][j-1]!=-1) {
                        f[i][j] = max(f[i][j], f[t-1][j-1] + cnt);
                    }
                }
                ans = max(ans, f[i][j]);
            }
        }
        return ans;
    }
};