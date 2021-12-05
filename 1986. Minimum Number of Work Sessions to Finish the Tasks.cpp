class Solution {
public:
    int minSessions(vector<int>& a, int sessionTime) {
        int n = a.size();
        vector<int> f(1<<n, n), g(1<<n);
        f[0] = 1;
        g[0] = 0;
        for (int i=1; i<(1<<n); ++i) {
            for (int j=0; j<n; ++j)
                if ((i>>j) & 1) {
                    int ti = i ^ (1<<j);
                    int tf = g[ti]+a[j]>sessionTime ? f[ti]+1 : f[ti];
                    int tg = g[ti]+a[j]>sessionTime ? a[j] : g[ti]+a[j];
                    if (tf < f[i] || tf==f[i] && tg<g[i]) {
                        f[i] = tf;
                        g[i] = tg;
                    }
                }
        }
        return f.back();
    }
};