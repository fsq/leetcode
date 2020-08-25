class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, mx = 0;
        for (auto x : nums) {
            int b = 0;
            while (x) {
                ++b;
                ans += x & 1;
                x >>= 1;
            }
            mx = max(mx , b);
        }
        return ans + mx - 1;
    }
};