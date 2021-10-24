class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        for (int i=0, t=nums.size(); i<t; ++i)
            nums.push_back(nums[i]);
        return nums;
    }
};