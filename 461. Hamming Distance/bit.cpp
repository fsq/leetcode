class Solution {
public:
    
    // https://leetcode.com/problems/hamming-distance/discuss/
    
    int hammingDistance(int x, int y) {
        x ^= y;
        int ans = 0;
        while (x>0) {
            ++ans;
            x &= x - 1; // clear the last 1
        }
        return ans;
    }
};