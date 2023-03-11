class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        for (int i=0; i+1<nums.size(); ++i) {
            if (st.count(nums[i]+nums[i+1]))
                return true;
            st.insert(nums[i] + nums[i+1]);
        }
        return false;
    }
};