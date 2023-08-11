class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> a(n, vector<int>(n));
        for (auto& q : queries) {
            ++a[q[2]][q[3]];
            if (q[0] > 0) {
                --a[q[0]-1][q[3]];
            }
            if (q[1] > 0) {
                --a[q[2]][q[1]-1];
            }
            if (q[0]>0 && q[1]>0) {
                a[q[0]-1][q[1]-1] += 1;
            }
        }
        for (int i=n-1; i>=0; --i)
            for (int j=n-1; j>=0; --j) {
                if (i+1==n && j+1==n) continue;
                if (i+1==n) {
                    a[i][j] += a[i][j+1];
                } else if (j+1==n) {
                    a[i][j] += a[i+1][j];
                } else {
                    a[i][j] += a[i+1][j] + a[i][j+1] - a[i+1][j+1];
                }
            }
        return a;
    }
};