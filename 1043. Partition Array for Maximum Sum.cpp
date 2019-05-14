class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& a, int k) {
        int n = a.size();
        vector<int> f(n);
        f[0] = a[0];
        
        for (int i=1; i<n; ++i) {
            f[i] = f[i-1] + a[i];
            int mx = a[i];
            for (int j=i-2; j>=0 && j>=i-k; --j) {
                mx = max(mx, a[j+1]);
                f[i] = max(f[i], f[j] + (i-j)*mx);
            }
            if (i<k) {
                mx = max(mx, f[0]);
                f[i] = max(f[i], (i+1)*mx);
            }
        }
        return f.back();
    }
};