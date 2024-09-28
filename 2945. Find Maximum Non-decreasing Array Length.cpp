class Solution {
public:
    int findMaximumLength(vector<int>& a) {
        int n = a.size();
        vector<long long> s(n+1), f(n+1), g(n+1), v(n+1), q; // v[i]=s[i]+g[i]
        for (int i=1; i<=n; ++i) s[i] = s[i-1] + a[i-1];
        f[0] = g[0] = 0;
        q.push_back(0);
        for (int i=1, p=0; i<=n; ++i) {
            while (p+1<q.size() && s[i]>=v[q[p+1]]) ++p;
            int j = q[p];
            f[i] = f[j] + 1;
            g[i] = s[i] - s[j];
            v[i] = s[i] + g[i];
            while (q.size() && v[q.back()] >= v[i]) q.pop_back();
            q.push_back(i);
        }
        return f[n];
    }
};