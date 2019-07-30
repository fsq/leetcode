class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> r = a, c = a;
        bool has1 = false;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                if (a[i][j]) has1 = true;
                if (i > 0) c[i][j] += c[i-1][j];
                if (j > 0) r[i][j] += r[i][j-1];
            }
        if (!has1) return 0;
        
        for (int len=min(n, m); len>0; --len) {
            for (int i=0; i+len<=n; ++i)
                for (int j=0; j+len<=m; ++j) {
                    int l1 = r[i][j+len-1] - (j==0 ? 0 : r[i][j-1]);
                    int l2 = c[i+len-1][j+len-1] - (i==0 ? 0 : c[i-1][j+len-1]);
                    int l3 = r[i+len-1][j+len-1] - (j==0 ? 0 : r[i+len-1][j-1]);
                    int l4 = c[i+len-1][j] - (i==0 ? 0 : c[i-1][j]);
                    if (l1==l2 && l2==l3 && l3==l4 && l4==len) 
                        return len * len;
                }
        }
        return 0;
    }
};