class Solution {
public:
    long long maximumStrength(vector<int>& a, int k) {
        reverse(a.begin(), a.end());
        int n = a.size();
        vector<vector<long long>> f(n, vector<long long>(k+1, LLONG_MIN));
        for (int i=0; i<n; ++i) f[i][0] = 0;
        vector<long long> s(n);
        s[0] = a[0];
        for (int i=1; i<n; ++i) s[i] = s[i-1] + a[i];
        for (long long j=1, sign=1; j<=k; ++j, sign*=-1) {
            long long mx = LLONG_MIN;
            if (j==1) mx = 0;
            for (int i=0; i<n; ++i) {
                if (i>0) f[i][j] = f[i-1][j];
                if (mx != LLONG_MIN) {
                    f[i][j] = max(f[i][j], mx + j*sign*s[i]);
                }
                if (f[i][j-1] != LLONG_MIN) {
                    mx = max(mx, f[i][j-1] - j*sign*s[i]);
                }
            }
        }
        return f[n-1][k];
    }
};