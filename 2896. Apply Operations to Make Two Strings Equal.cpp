class Solution {
public:

    int minOperations(string s1, string s2, int x) {
        vector<int> a;
        for (int i=0; i<s1.size(); ++i)
            if (s1[i] != s2[i]) {
                a.push_back(i);
            }
        if (a.size() & 1) return -1;
        if (a.empty()) return 0;
        int n = a.size();
        vector<int> f(n, INT_MAX);
        f[0] = x;
        for (int i=1; i<n; ++i) {
            f[i] = min(f[i-1] + x, (i-2>=0 ? f[i-2] : 0) + 2*min(x, a[i]-a[i-1]));
        }
        return f[n-1] / 2;

        // O(n^3) DP
        // vector<vector<int>> f(n, vector<int>(n, INT_MAX));
        // for (int l=2; l<=n; l+=2) {
        //     for (int i=0; i+l-1<n; ++i) {
        //         int j = i + l - 1;
        //         for (int k=i+1; k<=j; k+=2) {
        //             int cur = min(a[k]-a[i], x);
        //             if (k-1 > i+1) {
        //                 cur += f[i+1][k-1];
        //             }
        //             if (k+1 < j) {
        //                 cur += f[k+1][j];
        //             }
        //             f[i][j] = min(f[i][j], cur);
        //         }
        //     }
        // }
        // return f[0][n-1];
    }
};