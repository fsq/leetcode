class Solution {
public:
    int diagonalSum(vector<vector<int>>& a) {
        int n = a.size(), ans = 0;
        for (int i=0, j=0; i<n; ++i, ++j) {
            ans += a[i][j];
            a[i][j] = 0;
        }
        for (int i=0, j=n-1; i<n; ++i, --j)
            if (a[i][j] != 0) {
                ans += a[i][j];
            }
        return ans;
    }
};