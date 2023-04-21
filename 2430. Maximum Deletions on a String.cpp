class Solution {
public:
    int deleteString(string s) {
        int n = s.size();
        vector<vector<int>> m(n+1, vector<int>(n+1));
        for (int i=n-2; i>=0; --i)
            for (int j=i+1; j<n; ++j) {
                m[i][j] = s[i]==s[j] ? m[i+1][j+1]+1 : 0;
            }
        vector<int> f(n+1, 1); 
        f.back() = 0;
        for (int i=n-2; i>=0; --i) {
            for (int j=i+1; j+j-i<=n; ++j)
                if (m[i][j] >= j-i)
                    f[i] = max(f[i], f[j]+1);
        }
        return f[0];
    }
};