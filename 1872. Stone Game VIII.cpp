class Solution {
public:
    int stoneGameVIII(vector<int>& a) {
        int n = a.size();
        vector<int> f(n), g(n), s(n);
        partial_sum(a.begin(), a.end(), s.begin());
        f[n-1] = s.back();
        g[n-1] = -s.back();
        for (int i=n-2; i>=1; --i) {
            f[i] = max(f[i+1], s[i]+g[i+1]);
            g[i] = min(g[i+1], f[i+1]-s[i]);
        }
        return f[1];
    }
};