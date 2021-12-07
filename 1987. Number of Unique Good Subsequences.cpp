class Solution {
public:
    
    const int M = 1000000007;
    
    int numberOfUniqueGoodSubsequences(string s) {
        // f[0] : valid string ends with 0:  1...0
        // f[1] : valid string ends with 1:  1...1
        vector<int> f(2), g(2);
        bool has_zero = false;
        for (auto c : s) {
            if (c == '1') {
                // f[0] = g[0];
                if (g[1] == 0)
                    f[1] = 1; // "1"
                else 
                    f[1] = (g[1] + g[0] + 1)%M; // 1 for extra "1"
            } else {
                // f[1] = g[1];
                has_zero = true;
                if (g[0] == 0)
                    f[0] = g[1]; // 111..11 + "0"
                else 
                    f[0] = (g[0] + g[1])%M;
            }
            g = f;
        }
        return (g[0]+g[1]+has_zero) % M;
    }
};