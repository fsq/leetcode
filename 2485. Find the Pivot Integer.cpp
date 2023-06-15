class Solution {
public:
    int pivotInteger(int n) {
        int s = (1+n) * n / 2, p = 0;
        for (int i=1; i<=n; ++i) {
            p += i;
            if (p == s-p+i) return i;
        }
        return -1;
    }
};