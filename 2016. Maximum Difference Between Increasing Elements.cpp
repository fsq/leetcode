class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mx = nums.back(), ans = -1;
        for (int i=nums.size()-2; i>=0; --i) 
            if (mx > nums[i])
                ans = max(ans, mx - nums[i]);
            else 
                mx = nums[i];
        return ans;
    }
};