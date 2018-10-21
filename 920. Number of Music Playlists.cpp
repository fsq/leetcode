#define REP(i, a, b) for (int i=(a); i<=(b); ++i)
class Solution {
public:
    
    const int M = 1e9 + 7;
    long long f[203][203];
    
    int numMusicPlaylists(int n, int l, int k) {
        f[0][0] = 1;
        REP(i, 1, l)
            REP(j, 1, n)
                f[i][j] = (f[i-1][j-1]*(n-j+1) + f[i-1][j]*max(j-k, 0)) % M;
        return f[l][n];
    }
};