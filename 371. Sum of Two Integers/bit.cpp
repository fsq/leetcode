class Solution {
public:
    
    // https://leetcode.com/problems/sum-of-two-integers/description/
    // bit manipulation
    
    // split into 0/1 pairs and carry 1s
    int getSum(int x, int y) {
        return y==0 ? x : getSum(x^y, (x&y)<<1);
    }
    
    // bit by bit
    int getSum1(int x, int y) {
        int ans = 0, a,b,c=0;
        for (int i=0; i<32; ++i) {
            a = (x >> i) & 1;
            b = (y >> i) & 1;
            ans |= ((!a && (b!=c)) || (a && (b==c))) << i;
            c = (c && (a || b)) || (!c && a && b);
        }
        return ans;
    }
};