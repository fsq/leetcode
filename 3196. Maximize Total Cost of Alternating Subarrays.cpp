class Solution {
public:
    long long maximumTotalCost(vector<int>& a) {
        int n = a.size();
        if (n==1) return a[0];
        vector<vector<long long>> f(n, vector<long long>(2));
        f[1][0] = a[0] + a[1];
        f[1][1] = a[0] - a[1];
        for (int i=2; i<n; ++i) {
            f[i][0] = max(f[i-1][0], f[i-1][1]) + a[i];
            f[i][1] = f[i-1][0] - a[i];
        } 
        return max(f[n-1][0], f[n-1][1]);
    }
};