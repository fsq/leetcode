class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<int> r(n), c(m);
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (a[i][j]) {
                    ++r[i];
                    ++c[j];
                }
        auto ans = a;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                ans[i][j] = 2*r[i] - n + 2*c[j] - m;
        return ans;
    }
};