class Solution {
public:
    const int M = 1e9 + 7;
    int countSubMultisets(vector<int>& a, int l, int r) {
        unordered_map<int, int> m;
        vector<int> f(r+1);
        f[0] = 1;
        for (auto x : a) ++m[x];
        for (auto [x, cnt]: m) {
            // s[t] = f[t] + f[t-x] + f[t-2x] + ...
            vector<int> s(r + 1);
            for (int t=0; t<=r; ++t)
                if (t >= x)
                    s[t] = (s[t-x] + f[t]) % M;
                else
                    s[t] = f[t];
            for (int t=0; t<=r; ++t) 
                if (x > 0) {
                    int p = t - (cnt+1) * x;
                    f[t] = (s[t] - (p<0 ? 0: s[p]) + M) % M;
                } else {
                    f[t] = ((long long)f[t] * (cnt + 1)) % M;
                }
        }
        int ans = 0;
        for (int i=l; i<=r; ++i) ans = (ans + f[i]) % M;
        return ans;
    }
};