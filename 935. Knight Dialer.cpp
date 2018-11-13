class Solution {
public:
    const int M = 1e9 + 7;
    int knightDialer(int n) {
        vector<vector<int>> f(n+1, vector<int>(10));
        fill(f[1].begin(), f[1].end(), 1);
        for (int i=2; i<=n; ++i) {
            f[i][0] = (f[i-1][4]+f[i-1][6]) % M;
            f[i][1] = (f[i-1][8]+f[i-1][6]) % M;
            f[i][2] = (f[i-1][7]+f[i-1][9]) % M;
            f[i][3] = (f[i-1][4]+f[i-1][8]) % M;
            f[i][4] = ((f[i-1][3]+f[i-1][9]) % M + f[i-1][0]) % M;
            f[i][6] = ((f[i-1][1]+f[i-1][7]) % M + f[i-1][0]) % M;
            f[i][7] = (f[i-1][2]+f[i-1][6]) % M;
            f[i][8] = (f[i-1][1]+f[i-1][3]) % M;
            f[i][9] = (f[i-1][4]+f[i-1][2]) % M;
        }
        return accumulate(f.back().begin(), f.back().end(), 0ll) % M;
    }
};