class Solution {
public:
    int distMoney(int a, int b) {
        if (a < b) return -1;
        a -= b;
        int y = a % 7, x = a / 7;
        if (x > b)
            return b-1;
        else if (x == b)
            return y==0 ? b : b-1;
        else if (x <= b-2)
            return x;
        else
            return y==3 ? x-1 : x;
    }
};
