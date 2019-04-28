class Solution {
public:
    int solve(const vector<int>& a, const vector<int>& s, int l1, int l2) {
        int n = a.size();
        vector<int> f(n), g(n);
        f[l1-1] = s[l1-1];
        for (int i=l1; i<n; ++i) f[i] = max(f[i-1], s[i]-s[i-l1]);
        g[n-l2] = s[n-1] - s[n-l2-1];
        for (int i=n-l2-1; i>=0; --i) g[i] = max(g[i+1], s[i+l2-1] - (i==0 ? 0 :s[i-1]));
        int ans = 0;
        for (int i=l1-1; i+l2<n; ++i)
            ans = max(ans, f[i] + g[i+1]);
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& a, int l1, int l2) {
        int n = a.size();
        vector<int> s(n);
        partial_sum(a.begin(), a.end(), s.begin());
        
        return max(solve(a, s, l1, l2), solve(a, s, l2, l1));
    }
};