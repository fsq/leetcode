class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& a, int k) {
        auto ans = a;
        int n=a.size(), m=a[0].size();
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                int id = i*m + j + k;
                int r=id/m % n, c=id%m;
                ans[r][c] = a[i][j];
            }
        return ans;
    }
};