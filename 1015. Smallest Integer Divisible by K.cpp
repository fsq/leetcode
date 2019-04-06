class Solution {
public:
    
    int smallestRepunitDivByK(int K) {
        int r = 0;
        for (int i=1; i<=K; ++i) {
            r = (r*10 + 1) % K;
            if (!r) return i;
        }
        return -1;
    }
};