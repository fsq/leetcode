class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int n = a.size(), m = b.size();
        a.insert(a.begin(), ' ');
        b.insert(b.begin(), ' ');
        vector<vector<int>> f(n+1, vector<int>(m+1));
        f[0][0] = 0;
        for (int i=1; i<=n; ++i) 
            for (int j=1; j<=m; ++j) 
                if (a[i]==b[j]) {
                    f[i][j] = f[i-1][j-1] + 1;
                } else {
                    f[i][j] = max(f[i-1][j], f[i][j-1]);
                }
        string ans;
        int i=n, j=m;
        while (i>0 && j>0) 
            if (a[i]==b[j]) {
                ans.push_back(a[i]);
                --i, --j;
            } else if (f[i-1][j] > f[i][j-1]) {
                ans.push_back(a[i--]);
            } else {
                ans.push_back(b[j--]);
            }
        while (i) ans.push_back(a[i--]);
        while (j) ans.push_back(b[j--]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};