class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans(nums.size(), -1);
        if (2*k >= nums.size()) return ans;
        long long s = 0;
        for (int i=0; i<=2*k; ++i) s += nums[i];
        ans[k] = s / (2*k+1);
        for (int i=k+1; i+k<nums.size(); ++i) {
            s = s + nums[i+k] - nums[i-k-1];
            ans[i] = s / (2*k+1);
        }
        return ans;
    }
};