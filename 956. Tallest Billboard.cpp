class Solution {
public:
    int tallestBillboard(vector<int>& a) {
        int n = a.size();
        if (n==0) return 0;
        int s = accumulate(a.begin(), a.end(), 0) / 2;
        vector<vector<int>> f(n+1, vector<int>(s*2, -1));
        f[0][0] = 0;
        a.insert(a.begin(), 0);
        for (int i=1; i<=n; ++i) 
            for (int j=0; j<=s; ++j) {
                f[i][j] = f[i-1][j];
                if (f[i-1][j+a[i]]!=-1)
                    f[i][j] = max(f[i][j], f[i-1][j+a[i]]+a[i]);
                if (f[i-1][abs(a[i]-j)]!=-1)
                    f[i][j] = max(f[i][j], f[i-1][abs(a[i]-j)]+max(a[i]-j, 0));
            }
        return f[n][0];
            
    }
};