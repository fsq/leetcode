class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<long long>> f(n, vector<long long>(5));
        const int M = 1e9 + 7;
        
        for (int i=0; i<5; ++i) f[0][i] = 1;
        for (int i=0; i+1<n; ++i) {
            f[i+1][0] = (f[i][1] + f[i][2] + f[i][4]) % M;
            f[i+1][1] = (f[i][0] + f[i][2]) % M;
            f[i+1][2] = (f[i][1] + f[i][3]) % M;
            f[i+1][3] = f[i][2];
            f[i+1][4] = (f[i][2] + f[i][3]) % M;
        }
        
        return accumulate(f.back().begin(), f.back().end(), 0ll) % M;
    }
};