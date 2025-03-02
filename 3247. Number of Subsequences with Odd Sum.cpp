class Solution {
public:
    int subsequenceCount(vector<int>& nums) {
        long long a=0, ans=1;
        // ans = 2^(N-1)
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] & 1) {
                ++a;
            }
            if (i > 0)
                ans = (ans << 1) % 1000000007;
        }
        if (!a) return 0;
        return ans;
    }
};