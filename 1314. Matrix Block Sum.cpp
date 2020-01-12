class Solution {
public:
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& a, int K) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> s(n, vector<int>(m));
        s[0][0] = a[0][0];
        for (int i=1; i<n; ++i) s[i][0] = s[i-1][0] + a[i][0];
        for (int j=1; j<m; ++j) s[0][j] = s[0][j-1] + a[0][j];
        for (int i=1; i<n; ++i)
            for (int j=1; j<m; ++j) 
                s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
        auto calc = [&](int x1, int y1, int x2, int y2) {
            return s[x2][y2] - (x1>0 ? s[x1-1][y2] : 0) - (y1>0 ? s[x2][y1-1]:0) + (x1>0 && y1>0 ? s[x1-1][y1-1] : 0);
        };
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) 
                a[i][j] = calc(max(i-K, 0), max(j-K, 0), min(i+K, n-1), min(j+K, m-1));
        return a;
    }
};