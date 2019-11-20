class Solution {
public:
    int maxSumDivThree(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> f(n, vector<int>(3, INT_MIN));
        f[0][0] = 0;
        f[0][a[0]%3] = a[0];
        for (int i=1; i<n; ++i) 
            for (int j=0; j<3; ++j) {
                f[i][j] = max(f[i][j], f[i-1][j]);
                f[i][(j+a[i])%3] = max(f[i][(j+a[i])%3], f[i-1][j] + a[i]);
            }
        
        return f[n-1][0];
    }
};