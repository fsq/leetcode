class Solution {
public:
    int addMinimum(string word) {
        int ans = 0, target = 0;
        for (auto x : word) {
            while (x != 'a'+target) {
                ++ans;
                target = (target + 1) % 3;
            }
            target = (target + 1) % 3;
        }
        if (target) ans += 3 - target;
        return ans;
    }
};