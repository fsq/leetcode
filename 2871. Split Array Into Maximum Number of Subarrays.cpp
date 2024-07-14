class Solution {
public:
    int maxSubarrays(vector<int>& a) {
        int mn = -1;
        for (auto x : a) mn &= x;
        if (mn > 0) return 1;

        int ans = 0, cur = -1;
        for (auto x : a) {
            cur &= x;
            if (cur == mn) {
                ++ans;
                cur = -1;
            }
        }
        return ans;
    }
};