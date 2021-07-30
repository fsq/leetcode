class Solution {
public:
    int minSkips(vector<int>& a, long long speed, int hoursBefore) {
        int n = a.size();
        vector<vector<long long>> f(n+1, vector<long long>(n+1, LLONG_MAX));
        f[0][0] = f[0][1] = 0;
        for (int i=1; i<=n; ++i) {
            f[i][1] = f[i-1][1] + a[i-1];
            for (int j=2; j<=i; ++j) {
                f[i][j] = (f[i-1][j-1]+speed-1)/speed*speed+a[i-1];
                if (i-1 >= j)
                    f[i][j] = min(f[i-1][j]+a[i-1], f[i][j]);
            }
        }
        for (int i=n; i>=1; --i)
            if (f[n][i]<=hoursBefore*speed) 
                return n - i;
        return -1;
    }
};