class Solution {
public:
    int minimumXORSum(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> f(1<<n, INT_MAX);
        f[0] = 0;
        for (int i=1; i<(1<<n); ++i) {
            int m = __builtin_popcount(i);
            for (int j=0; j<n; ++j)
                if ((i>>j) & 1) 
                    f[i] = min(f[i], f[i ^ (1<<j)] + (a[m-1] ^ b[j]));
        }
        return f.back();
    }
};