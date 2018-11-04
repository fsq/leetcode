class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> f(n, vector<int>(n, INT_MAX));
        for (int i=0; i<n; ++i) f[0][i] = a[0][i];
        
        for (int i=1; i<n; ++i)
            for (int j=0; j<n; ++j)
                for (int d=-1; d<=1; ++d)
                    if (j+d>=0 && j+d<n)
                        f[i][j] = min(f[i][j], f[i-1][j+d]+a[i][j]);

        return *min_element(f.back().begin(), f.back().end());
    }
};