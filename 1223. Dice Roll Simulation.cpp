class Solution {
public:
    int f[5001][6], s[5001];
    const int M = 1e9 + 7;
    
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(f, 0, sizeof(f));
        memset(s, 0, sizeof(s));
        for (int i=0; i<6; ++i) 
            s[1] += f[1][i] = 1;
        s[0] = 1;
        
        for (int i=2; i<=n; ++i)
            for (int j=0; j<6; ++j) {
                f[i][j] = s[i-1];
                if (i>=rollMax[j]+1)
                    f[i][j] = ((f[i][j] + f[i-rollMax[j]-1][j]) % M - s[i-rollMax[j]-1] + M) % M;
                s[i] = (s[i] + f[i][j]) % M;
            }
        return s[n];
    }
};