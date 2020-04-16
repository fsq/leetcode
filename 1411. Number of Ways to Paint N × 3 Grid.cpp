class Solution {
public:
    const int M = 1e9 + 7;
    int numOfWays(int n) {
        long ans = 0, c2 = 6, c3 = 6;
        for (int i=1; i<n; ++i) {
            int pc2 = c2;
            c2 = (3*c2 + 2*c3) % M;
            c3 = (2*pc2 + 2*c3) % M;
        }
        return (c2 + c3) % M;
    }
};