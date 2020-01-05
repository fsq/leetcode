class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int s = 0, i = 31;
        while (i>=0 && (m>>i & 1) == (n>>i & 1)) {
            s |= (m>>i & 1) << i;
            --i;
        }
        return s;
    }
};