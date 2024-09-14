class Solution {
public:
    
    int stringCount(int n) {
        vector<long long> f(12), g(12);
        g[0] = 1;
        // Can optimize to logn with fast power
        for (int i=1; i<=n; ++i) {
            f[0] = g[0]*23; // none
            f[1] = g[0] + g[1]*24; // l
            f[2] = g[0] + g[2]*23; // e
            f[3] = g[0] + g[3]*24; // t
            f[4] = g[1] + g[2] + g[4]*24; // le
            f[5] = g[1] + g[3] + g[5]*25; // lt
            f[6] = g[2] + g[6]*24; // ee
            f[7] = g[2] + g[3] + g[7]*24; // et
            f[8] = g[4] + g[6] + g[8]*25; // lee
            f[9] = g[4] + g[5] + g[7] + g[9]*25; // let
            f[10] = g[6] + g[7] + g[10]*25; // eet
            f[11] = g[8] + g[9] + g[10] + g[11]*26; // leet
            g = f;
            for (auto& x : g) x %= 1000000007;
        }
        return g[11];
    }
};