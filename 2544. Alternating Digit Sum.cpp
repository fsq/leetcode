class Solution {
public:
    int alternateDigitSum(int n) {
        int l=0, s=0, v=1;
        while (n) {
            s += (n%10) * v;
            n /= 10;
            v *= -1;
            ++l;
        }
        if (!(l&1)) s *= -1;
        return s;
    }
};