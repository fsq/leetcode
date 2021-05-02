class Solution {
public:
    int reinitializePermutation(int n) {
        int p1 = 1, ans = 0;
        do {
            if (p1 % 2 == 0) p1 = p1 / 2; else p1 = n / 2 + p1 / 2;
            ++ans;
        } while (p1 != 1);
        return ans;
    }
};