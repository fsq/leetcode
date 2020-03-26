class Solution {
public:
    
    int solve(vector<int> a, int k) {
        int n = a.size();
        vector<vector<int>> f(n, vector<int>(k+1));
        f[0][1] = a[0];
        f[1][1] = max(a[0], a[1]);
        for (int i=2; i<n; ++i) {
            f[i][0] = 0;
            for (int j=1; j<=k; ++j) f[i][j] = max(f[i-1][j], f[i-2][j-1]+a[i]);
        }
        return f[n-1][k];
    }
    
    int maxSizeSlices(vector<int>& a) {
        if (a.size()==3) return *max_element(a.begin(), a.end());
        return max(solve(vector<int>(a.begin(), a.end()-1), a.size()/3), solve(vector<int>(a.begin()+1, a.end()), a.size()/3));
    }
};