class Solution {
public:
    
    // https://leetcode.com/problems/valid-triangle-number/description/
    // O(n^2+nlogn) time O(1) space
    // sort 
    // enumerate the longest edge c
    // apply 'two sum smaller than c' two pointers technique to prefix
    
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i=nums.size()-1; i>=0; --i) {
            int c = nums[i];
            int l = 0, r = i-1;
            while (l<r) 
                if (nums[l]+nums[r]>c) {
                    ans += r - l;
                    --r;
                } else 
                    ++l;
        }
        return ans;
    }
};