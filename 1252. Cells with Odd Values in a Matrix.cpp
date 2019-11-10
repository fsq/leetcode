class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> a(n, vector<int>(m));
        for (auto& pr : indices)
            ++a[pr[0]][pr[1]];
        
        vector<int> r(n), c(m);
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                r[i] += a[i][j];
                c[j] += a[i][j];
            }
    
        int ans = 0;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) 
                ans += (r[i]+c[j]-2*a[i][j]) & 1;
        return ans;
    }
};