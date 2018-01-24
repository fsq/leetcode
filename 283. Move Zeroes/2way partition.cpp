class Solution {
public:
    
    // https://leetcode.com/problems/move-zeroes/description/
    // O(n) time O(1) space 2 way partition
    
    void moveZeroes(vector<int>& nums) {
        for (int j=0, i=0; j<nums.size(); ++j)
            if (nums[j]!=0)
                swap(nums[i++], nums[j]);
    }
};