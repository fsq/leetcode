class Solution {
public:
    const int M = 1000000007;
    long long cs[10001][15];

    long long C(int n, int x) {
        if (n==0) return 0;
        if (x==0 || n==x) return 1;
        if (cs[n][x] > 0) return cs[n][x];
        cs[n][x] = (C(n-1, x) + C(n-1, x-1)) % M;
        return cs[n][x];
    }

    int idealArrays(long long n, int maxValue) {
        vector<vector<long long>> f(16, vector<long long>(maxValue+1));
        memset(cs, 0, sizeof(cs));
        long long ans = 1;
        f[1][1] = 1;
        for (int i=1; (1<<i)<=maxValue; ++i) {
            for (int j=2; j<=maxValue; ++j) {
                if (i==1)
                    f[i][j] = 1;
                else {
                    for (int k=2; k<=sqrt(j); ++k)
                        if (j % k == 0) {
                            if (k*k != j)
                                f[i][j] = (f[i][j] + f[i-1][j/k] + f[i-1][k]) % M;
                            else
                                f[i][j] = (f[i][j] + f[i-1][k]) % M;
                        }
                }
                if (f[i][j] > 0) {
                    ans = (ans + C(n, i) * f[i][j]) % M;
                }
            }
        }
        return ans;
    }
};