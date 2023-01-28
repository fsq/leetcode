class Solution {
public:
    int equalPairs(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> r(n), c(m);
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                r[i].push_back(a[i][j]);
                c[j].push_back(a[i][j]);
            }
        int ans = 0;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (r[i] == c[j])
                    ++ans;
        return ans;
    }
};