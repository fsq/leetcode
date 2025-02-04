class Solution {
public:
    const int M = 1000000007;

    int numberOfPermutations(int n, vector<vector<int>>& rq) {
        vector<int> r(n+1, -1);
        int m = 0;
        for (auto& a: rq) {
            r[a[0]] = a[1];
            m = max(m, a[1]);
        }
        vector<vector<int>> f(n+1, vector<int>(m+1));
        f[0][0] = 1;
        for (int i=0; i+1<n; ++i) {
            int mn=0, mx=m;
            if (r[i]!=-1) {
                mn = mx = r[i];
            }
            for (int j=mn; j<=mx; ++j) {
                if (f[i][j]) {
                    // can further optimize. calculate f[i][j] with prefix sum of f[i-1][...]
                    for (int k=i+1; k>=0 && j+i+1-k<=m; --k) {
                        f[i+1][j+i+1-k] = (f[i+1][j+i+1-k] + f[i][j]) % M;
                    }
                }
            }
        }
        return f[n-1][r[n-1]];
    }
};