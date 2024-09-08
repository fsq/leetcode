class Solution {
public:
    long long minIncrementOperations(vector<int>& a, int k) {
        int n = a.size();
        vector<long long> g(n+3), f(n+3);
        auto df = [=](long long x) {
            return x >= k ? 0 : k - x;
        };
        for (int i=n-1; i>=0; --i) {
            g[i] = df(a[i]) + f[i+1];
            f[i] = g[i];
            for (int j=i+1; j<=i+2; ++j) {
                f[i] = min(f[i], g[j]);
            }
        }
        return f[0];
    }
};