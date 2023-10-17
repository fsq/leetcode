class Solution {
public:
    int M = 1000000007;

    int waysToReachTarget(int target, vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> f(n+1, vector<int>(target+1));
        f[0][0] = 1;
        for (int i=1; i<=n; ++i) {
            int c = a[i-1][0], p = a[i-1][1];
            f[i][0] = f[i-1][0];
            for (int j=1; j<=target; ++j) {
                f[i][j] = f[i-1][j];
                for (int k=1; k<=c && k*p<=j; ++k) {
                    f[i][j] = (f[i][j] + f[i-1][j-k*p]) % M;
                }
            }
        }
        return f[n][target];
    }
};