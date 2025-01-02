class Solution {
public:
    int f[1002][1002][2] = {0};
    int s[1002] = {0};
    const int M = 1000000007;

    // f[zero][one][0] = sum(f[zero-k][one][1]) k in [1..limit]
    // f[zero][one][1] = sum(f[zero][one-k][0]) k in [1..limit]
    int numberOfStableArrays(int zero, int one, int limit) {
        f[0][0][0] = 1;
        f[0][0][1] = 1;
        for (int i=0; i<=zero; ++i) {
            for (int j=0; j<=one; ++j) {
                if (i>0) {
                    f[i][j][0] = (f[i-1][j][0] + (j>0 ? f[i-1][j][1]:0)) % M;
                    if (i-1-limit>=0) {
                        f[i][j][0] = (f[i][j][0] - f[i-1-limit][j][1] + M) % M;
                    }
                }
                if (j>0) {
                    f[i][j][1] = (f[i][j-1][1] + (i>0 ? f[i][j-1][0]:0)) % M;
                    if (j-1-limit>=0) {
                        f[i][j][1] = (f[i][j][1] - f[i][j-1-limit][0] + M) % M;
                    }
                }
            }
        }
        return (f[zero][one][0] + f[zero][one][1]) % M;
    }
};