class Solution {
public:
    
    int n, m;
    vector<vector<int>> f;
    
    int dp(vector<int>& a, vector<int>& b, int l, int r) {
        if (l + r == m) return 0;
        if (f[l][r] != INT_MIN) return f[l][r];
        int& ans = f[l][r];
        ans = max(a[l]*b[l+r] + dp(a, b, l+1, r), a[n-1-r]*b[l+r] + dp(a, b, l, r+1));
        return ans;
    }
    
    int maximumScore(vector<int>& a, vector<int>& b) {
        n = a.size(), m = b.size();
        f = vector<vector<int>>(m, vector<int>(m, INT_MIN));
        return dp(a, b, 0, 0);
    }
};