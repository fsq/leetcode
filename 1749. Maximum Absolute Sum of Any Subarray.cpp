class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mx=0, mn=0, ans = 0;
        for (auto x : nums) {
            mx = max(x, mx+x);
            mn = min(x, mn+x);
            ans = max(ans, max(abs(mx), abs(mn)));
        }
        return ans;
    }
};