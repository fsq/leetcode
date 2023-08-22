class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        while (targetX%2==0) targetX /= 2;
        while (targetY%2==0) targetY /= 2;
        return gcd(targetX, targetY) == 1;
    }
};