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
            // s[j] = sum(f[i-k][j][1]) k in [1..limit]
            // pf = sum(f[i][j-k][0]) k in [1..limit]
            int pf = 0;
            for (int j=0; j<=one; ++j) {
                if (i==0 && j==0) continue;
                if (i>0) s[j] = (s[j] + f[i-1][j][1]) % M;
                if (i-limit-1>=0) {
                    s[j] = (s[j] - f[i-limit-1][j][1] + M) % M;
                }
                if (j>0) pf = (pf + f[i][j-1][0]) % M;
                if (j-limit-1>=0) {
                    pf = (pf - f[i][j-limit-1][0] + M) % M;
                }
                f[i][j][0] = s[j];
                f[i][j][1] = pf;
            }
        }
        return (f[zero][one][0] + f[zero][one][1]) % M;
    }
};