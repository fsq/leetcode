class Solution {
public:
    int rev(int x) {
        int y = 0;
        while (x) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y;
    }

    bool sumOfNumberAndReverse(int n) {
        for (int i=0; i<=n; ++i)
            if (i+rev(i)==n) {
                return true;
            } 

        return false;
    }
};