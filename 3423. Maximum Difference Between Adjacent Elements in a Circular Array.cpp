#include <ranges>

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans = 0;
        for (int i: ranges::views::iota(0, (int)nums.size())) {
            ans = max(ans, abs(nums[i] - nums[(i+1)%nums.size()]));
        }
        return ans;
    }
};