class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& a) {
        vector<int> x(3), y(3);
        int n = a.size();
        for (int i=0; i<=n/2; ++i) {
            ++y[a[i][i]];
            a[i][i] = -1;
            if (i<n/2) {
                ++y[a[i][n-i-1]];
                a[i][n-i-1] = -1;
            }
        }
        for (int i=n/2+1; i<n; ++i) {
            ++y[a[i][n/2]];
            a[i][n/2] = -1;
        }
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (a[i][j] != -1)
                    ++x[a[i][j]];
        // cout << x[0] << ' ' << x[1] << ' ' << x[2] << endl;
        // cout << y[0] << ' ' << y[1] << ' ' << y[2] << endl;
        int ans = INT_MAX;
        for (int cx=0; cx<3; ++cx)
            for (int cy=0; cy<3; ++cy)
                if (cx != cy) {
                    int cost = 0;
                    for (int i=0; i<=2; ++i) {
                        if (i!=cx) cost += x[i];
                        if (i!=cy) cost += y[i];
                    }
                    ans = min(ans, cost);
                }
        return ans;
    }
};