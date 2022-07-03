class Solution {
public:
    bool checkValid(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> r(n, vector<int>(n)), c(n, vector<int>(n));
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j) {
                r[i][a[i][j]-1] = 1;
                c[j][a[i][j]-1] = 1;
            }
        for (int i=0; i<n; ++i) {
            if (accumulate(r[i].begin(), r[i].end(), 0) != n) return false;
            if (accumulate(c[i].begin(), c[i].end(), 0) != n) return false;
        }
        return true;
    }
};