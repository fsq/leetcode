class Solution {
public:
    const int M = 1000000007;
    int countPartitions(vector<int>& a, int k) {
        if (accumulate(a.begin(), a.end(), 0ll) < 2*k) return false;
        int n = a.size();
        vector<vector<int>> f(n+1, vector<int>(k+1));
        f[0][0] = 1;
        long long two=1;
        for (int i=1; i<=n; ++i) {
            int x = a[i-1];
            f[i] = f[i-1];
            two = two * 2 % M;
            for (int j=0; j<=k-x; ++j) {
                f[i][j+x] = (f[i][j+x] + f[i-1][j]) % M;
            }
        }
        long long less = accumulate(f[n].begin(), f[n].begin()+k, 0ll) % M;
        return ((two - less - less) % M + M) % M;
    }
};