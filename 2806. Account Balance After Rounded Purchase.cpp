class Solution {
public:
    int accountBalanceAfterPurchase(int x) {
        if (x % 10 < 5) {
            x = x / 10 * 10;
        } else {
            x = (x + 9) / 10 * 10;
        }
        return 100 - x;
    }
};