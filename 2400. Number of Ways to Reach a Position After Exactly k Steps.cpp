class Solution {
public:

    const int MK = 1000; // -1000, 1000 -> 0  2000
    const int M = 1000000007;

    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> f(k+1, vector<int>(MK*2+1));
        f[0][startPos-endPos+MK] = 1;
        for (int i=1; i<=k; ++i)
            for (int j=-MK; j<=MK; ++j) {
                if (j!=-MK) f[i][j+MK] = (f[i-1][j+MK-1] + f[i][j+MK]) % M;
                if (j!=MK)  f[i][j+MK] = (f[i-1][j+MK+1] + f[i][j+MK]) % M;
            }
        return f[k][MK];
    }
};