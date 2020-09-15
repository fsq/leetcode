class Solution {
public:
    int numSpecial(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<int> r(n), c(m);
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                r[i] += a[i][j];
                c[j] += a[i][j];
            }
        int ans = 0;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (a[i][j] && r[i]==1 && c[j]==1)
                    ++ans;
        return ans;
    }
};