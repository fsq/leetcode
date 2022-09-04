class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if (k==0) return nums[0];
        if (nums.size()==1) return (k&1) ? -1 : nums[0];
        if (k==1) return nums.size()>1 ? nums[1] : -1;

        int ans = *max_element(nums.begin(), nums.begin()+min<int>(nums.size(), k-1));
        if (nums.size() > k) ans = max(ans, nums[k]);
        return ans;
    }
};