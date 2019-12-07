class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        
        vector<vector<int>> change(n+1, vector<int>(n+1));
        for (int l=2; l<=n; ++l)
            for (int i=0; i+l<=n; ++i) {
                int j = i + l - 1;
                change[i][j] = change[i+1][j-1] + (s[i]!=s[j]);
            }
        
        vector<vector<int>> f(n, vector<int>(k+1, INT_MAX));
        for (int i=0; i<n; ++i) {
            f[i][1] = change[0][i];
            for (int j=2; j<=min(i+1, k); ++j) {
                for (int pre=0; pre<i; ++pre) 
                    if (f[pre][j-1] != INT_MAX)
                        f[i][j] = min(f[i][j], f[pre][j-1] + change[pre+1][i]);
            }
        }
        return f[n-1][k];
    }
};