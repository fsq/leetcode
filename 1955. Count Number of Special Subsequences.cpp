class Solution {
public:
    const int M = 1000000007;
    
    int countSpecialSubsequences(vector<int>& a) {
        vector<long long> f(3);
        for (auto x : a) {
            if (x == 0)
                f[0] = (f[0] + f[0] + 1) % M;
            else if (x == 1)
                f[1] = (f[1] + f[1] + f[0]) % M;
            else if (x == 2)
                f[2] = (f[2] + f[2] + f[1]) % M;
        }
        return f[2];
    }
};