class Solution {
public:
    int maxSatisfied(vector<int>& a, vector<int>& s, int m) {
        int n = a.size();
        for (auto& x : s) x ^= 1;
        vector<int> f(n), p(n);
        f[0] = a[0] * s[0];
        p[0] = a[0];
        for (int i=1; i<n; ++i) {
            f[i] = f[i-1] + a[i]*s[i];
            p[i] = p[i-1] + a[i];
        }
        int ans = 0;
        for (int i=0; i+m<=n; ++i) {
            int sum = i==0 ? 0 : f[i-1];
            sum += i==0 ? p[i+m-1] : p[i+m-1] - p[i-1];
            sum += f[n-1] - f[i+m-1];
            ans = max(ans, sum);
        }
        return ans;
    }
};