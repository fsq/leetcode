class Solution {
public:
    
    const int M = 1e9 + 7;
    
    int numberOfWays(int n) {
        vector<long long> f(n+1);
        f[0] = 1;
        for (int i=2; i<=n; i+=2) {
            for (int j=1; j<i; j+=2)
                f[i] = (f[i] + f[j-1] * f[i-j-1]) % M;
        }
        return f[n];
    }
};