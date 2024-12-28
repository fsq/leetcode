class Solution {
public:
    int maxBottlesDrunk(int b, int c) {
        int ans = 0, e = 0;
        while (b) {
            --b;
            ++ans;
            ++e;
            if (e >= c) {
                ++b;
                e -= c;
                ++c;
            }
        }
        return ans;
    }
};