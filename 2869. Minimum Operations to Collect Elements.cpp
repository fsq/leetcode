class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;
        for (int i = nums.size()-1; i>=0; --i)
            if (nums[i] >= 1 && nums[i] <= k) {
                st.insert(nums[i]);
                if (st.size() == k) {
                    return nums.size() - i;
                }
            }
        return 0;
    }
};