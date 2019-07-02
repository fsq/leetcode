class Solution {
public:
    int minHeightShelves(vector<vector<int>>& a, int w) {
        int n = a.size();
        vector<int> f(n);
        f[0] = a[0][1];
        for (int i=1; i<n; ++i) {
            int mx = a[i][1], cw = a[i][0];
            f[i] = f[i-1] + mx;
            for (int j=i-1; j>=0 && cw+a[j][0]<=w; --j) {
                cw += a[j][0];
                mx = max(mx, a[j][1]);
                f[i] = min(f[i], (j==0 ? 0 : f[j-1]) + mx);
            }
        }
        return f.back();
    }
};