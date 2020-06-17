class Solution {
public:
    int minDistance(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int n = a.size();
        vector<vector<int>> f(n+1, vector<int>(k+1, INT_MAX)), s(n+1, vector<int>(n+1));
        for (int i=1; i<=n; ++i) {
            int tot = 0;
            for (int j=i; j<=n; ++j) {
                tot += a[j-1];
                int mid = a[(i-1+j-1)/2];
                for (int k=i; k<=j; ++k)
                    s[i][j] += abs(mid - a[k-1]);
            }
        }
        f[1][1] = 0;
        for (int i=2; i<=n; ++i) {
            f[i][1] = s[1][i];
            for (int j=2; j<=min(k, i); ++j) {
                f[i][j] = INT_MAX;
                for (int pre=1; pre<i; ++pre)
                    if (f[pre][j-1]!=INT_MAX)
                        f[i][j] = min(f[i][j], f[pre][j-1] + s[pre+1][i]);
            }
        }
        return f[n][k];
    }
};