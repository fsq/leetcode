class Solution {
public:
    bool isPerfectSquare(int num) {
        int x = sqrt(num);
        return x*x == num;
    }
};