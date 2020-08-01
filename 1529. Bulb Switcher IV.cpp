class Solution {
public:
    int minFlips(string target) {
        int ans = 0, now = 0;
        for (auto c : target)
            if (now != c-'0') {
                ++ans;
                now ^= 1;
            }
        return ans;
    }
};