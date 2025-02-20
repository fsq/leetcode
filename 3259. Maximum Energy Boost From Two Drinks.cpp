class Solution {
public:
    long long maxEnergyBoost(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<vector<long long>> f(n+1, vector<long long>(2));
        for (int i=1; i<=n; ++i) {
            f[i][0] = max(f[i-1][0], (i>=2 ? max(f[i-2][0], f[i-2][1]) : 0)) + a[i-1];
            f[i][1] = max(f[i-1][1], (i>=2 ? max(f[i-2][0], f[i-2][1]) : 0)) + b[i-1];
        }
        return max(f[n][0], f[n][1]);
    }
};