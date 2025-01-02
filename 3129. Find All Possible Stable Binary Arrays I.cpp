class Solution {
public:
    int f[203][203][203][2] = {0};
    const int M = 1000000007;

    // f[zero][one][consecutive count][0/1]
    int numberOfStableArrays(int zero, int one, int limit) {
        f[0][0][0][0] = 1;
        for (int i=0; i<=zero; ++i)
            for (int j=0; j<=one; ++j)
                for (int c=0; c<=limit; ++c) {
                    // last is 1
                    // append 0
                    f[i+1][j][1][0] = (f[i+1][j][1][0] + f[i][j][c][1]) % M;
                    // append 1
                    if (c<limit) {
                        f[i][j+1][c+1][1] = (f[i][j+1][c+1][1] + f[i][j][c][1]) % M;
                    }
                    // last is 0
                    // append 1
                    f[i][j+1][1][1] = (f[i][j+1][1][1] + f[i][j][c][0]) % M;
                    // append 0
                    if (c<limit) {
                        f[i+1][j][c+1][0] = (f[i+1][j][c+1][0] + f[i][j][c][0]) % M;
                    }
                }
        int ans = 0;
        for (int i=0; i<=limit; ++i)
            for (int k=0; k<2; ++k)
                ans = (ans + f[zero][one][i][k]) % M;
        return ans;
    }
};