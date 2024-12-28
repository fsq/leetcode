class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int y = 0;
        for (int t=x; t; t/=10) y += t % 10;
        return x % y == 0 ? y : -1;
    }
};