class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> m;
        int ans, target;
        for (int i=0; i+1<nums.size(); ++i)
            if (nums[i] == key && ++m[nums[i+1]]>ans) {
                target = nums[i+1];
                ans = m[nums[i+1]];
            }
        return target;
    }
};