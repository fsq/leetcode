class Solution {
public:
    int minDeletionSize(vector<string>& a) {
        int n = a[0].size(), m = a.size();
        int ans = n;
        vector<int> f(n);
        for (int i=0; i<n; ++i) {
            f[i] = i;
            for (int j=0; j<i; ++j) {
                bool ls = true;
                for (int k=0; k<m; ++k)
                    if (a[k][j]>a[k][i]) {
                        ls = false;
                        break;
                    }
                if (ls) f[i] = min(f[i], f[j] + (i-j-1));
            }
            ans = min(ans, f[i]+(n-1-i));
        }
        return ans;
    }
};