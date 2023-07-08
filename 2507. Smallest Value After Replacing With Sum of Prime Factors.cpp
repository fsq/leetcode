class Solution {
public:
    int smallestValue(int n) {
        while (true) {
            int f = 2, nxt = 0, pre = n;
            while (n > 1) {
                while (n % f == 0) {
                    n /= f;
                    nxt += f;
                }
                ++f;
            }
            n = nxt;
            if (pre == nxt) break;
        }
        return n;
    }
};