class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        long long ans = 0, i = 0, x = 1;
        while (k)
            if (i<nums.size() && nums[i]==x) {
                ++i;
                ++x;
            } else {
                int y = i<nums.size() ? min<long long>(nums[i]-1, x+k-1) : x+k-1;
                ans += (x+y)*(y-x+1)/2;
                k -= y - x + 1;
                x = y + 1;
            }
        return ans;
    }
};