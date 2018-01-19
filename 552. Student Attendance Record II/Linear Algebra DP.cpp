class Solution {
public:
    // https://leetcode.com/problems/student-attendance-record-ii/description/
    // O(logn) linear algebra solution
    // start from DP: f[n][i][j]=#records of n days, i As, ends with j Ls.
    // f[n][0][0] = f[n-1][0][0,1,2]
    // f[n][0][1] = f[n-1][0][0]
    // f[n][0][2] = f[n-1][0][1]
    // f[n][1][0] = f[n-1][0][0,1,2] + f[n-1][1][0,1,2]
    // f[n][1][1] = f[n-1][1][0]
    // f[n][1][2] = f[n-1][1][1]
    
    // flatten to 1D array and use matrix M to represent the transition functions
    // f[n] = M * f[n-1]
    // f[n] = M^n * f[0]
    // use fast power algorithm gives O(logn)
    
    const long MOD = 1e9 + 7;
    vector<vector<long>> I = {{1,0,0,0,0,0},
                              {0,1,0,0,0,0},
                              {0,0,1,0,0,0},
                              {0,0,0,1,0,0},
                              {0,0,0,0,1,0},
                              {0,0,0,0,0,1}};
    
    vector<vector<long>> matrix_multiply(const vector<vector<long>>& a, const vector<vector<long>>& b) {
        vector<vector<long>> c(a.size(), vector<long>(b[0].size()));
        for (int i=0; i<c.size(); ++i)
            for (int j=0; j<c[0].size(); ++j)
                for (int k=0; k<a[0].size(); ++k)
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
        return c;
    }
    
    vector<vector<long>> pow(const vector<vector<long>>& M, int n) {
        if (n==0) return I;
        if (n==1) return M;
        auto sub = pow(M, n>>1);
        return (n&1) ? matrix_multiply(matrix_multiply(sub, sub), M) :
                       matrix_multiply(sub, sub);
    }
    
    int checkRecord(int n) {
        vector<vector<long>> M = {{1,1,1,0,0,0},
                                  {1,0,0,0,0,0},
                                  {0,1,0,0,0,0},
                                  {1,1,1,1,1,1},
                                  {0,0,0,1,0,0},
                                  {0,0,0,0,1,0}};
        auto result = matrix_multiply(pow(M, n), vector<vector<long>>{{1},{0},{0},{0},{0},{0}});
        return (result[0][0]+result[1][0]+result[2][0]+result[3][0]+result[4][0]+result[5][0]) % MOD;
    }
};