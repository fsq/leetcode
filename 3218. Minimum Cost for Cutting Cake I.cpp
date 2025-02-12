class Solution {
public:
    // O(n*m) dp
    int minimumCost(int n, int m, vector<int>& a, vector<int>& b) {
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        vector<vector<int>> f(n+1, vector<int>(m+1));
        for (int i=1; i<=a.size(); ++i) f[i][0] = f[i-1][0] + a[i-1];
        for (int i=1; i<=b.size(); ++i) f[0][i] = f[0][i-1] + b[i-1];
        for (int i=1; i<=a.size(); ++i) {
            for (int j=1; j<=b.size(); ++j) {
                f[i][j] = min(f[i-1][j] + a[i-1]*(j+1), f[i][j-1] + b[j-1]*(i+1));
            }
        }
        return f[n-1][m-1];
    }
};