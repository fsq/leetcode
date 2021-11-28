class Solution {
public:
    const int M = 1000000007;
    vector<int> nne;
    
    bool ge(const string& s, const vector<vector<int>>& p, 
            int l1, int r1, int l2, int r2) {
        int l = p[l2][l1];
        if (l >= r1-l1+1) return true;
        return s[l1+l] >= s[l2+l];
    }
    
    int numberOfCombinations(string s) {
        int n = s.size();
        vector<vector<int>> f(n+1, vector<int>(n+1));
        vector<vector<int>> p(n+1, vector<int>(n+1)); //longest common prefix
        p[n-1][n] = 0;
        for (int i=n-2; i>=0; --i)
            for (int j=n-1; j>i; --j) {
                p[i][j] = s[i]==s[j] ? (p[i+1][j+1]+1) : 0;
            }
        for (int i=1; i<=s.size(); ++i) {
            for (int j=1; j<i; ++j) {
                if (f[i-j][j] && i>=2*j && 
                    s[i-j]!='0' &&
                    ge(s, p, i-j, i-1, i-j-j, i-j-1)) {
                    f[i][j] = f[i-j][j];                
                } else if (s[i-j]!='0') {
                    f[i][j] = f[i-j][min(j-1, i-j)];
                }
                f[i][j] = (f[i][j-1] + f[i][j]) % M;
            }
            f[i][i] = s[0]=='0' ? f[i][i-1] : f[i][i-1]+1;
        }
        return f[n][n];
    }
};