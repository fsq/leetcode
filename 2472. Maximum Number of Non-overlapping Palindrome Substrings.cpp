class Solution {
public:
    int maxPalindromes(string s, int k) {
        if (k==1) return s.size();
        int n = s.size();
        vector<vector<int>> pan(n+1, vector<int>(n+1));

        for (int i=0; i<n; ++i) {
            pan[i][i] = 1;
            if (i+1<n) pan[i][i+1] = s[i]==s[i+1];
        }
        for (int len=3; len<=n; ++len)
            for (int i=0; i+len<=n; ++i)
                pan[i][i+len-1] = s[i]==s[i+len-1] && pan[i+1][i+len-2];
        
        vector<int> f(n+1);
        for (int i=k-1; i<n; ++i) {
            f[i] = f[i-1];
            for (int j=i-k+1; j>=0; --j)
                if (pan[j][i]) {
                    f[i] = max(f[i], 1 + (j==0 ? 0 : f[j-1]));
                    break;
                }
        }
        return f[n-1];
    }
};