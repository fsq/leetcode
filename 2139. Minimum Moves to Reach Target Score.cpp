class Solution {
public:
    int minMoves(int x, int maxDoubles) {
        int ans = 0;
        while (x != 1) {
            if (maxDoubles == 0) {
                ans += x - 1;
                break;
            } else if (x & 1) {
                --x;
            } else {
                --maxDoubles;
                x /= 2;
            }
            ++ans;
        }
        return ans;
    }
};