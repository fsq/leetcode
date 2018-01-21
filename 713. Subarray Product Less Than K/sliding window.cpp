class Solution {
public:
    
    // https://leetcode.com/problems/subarray-product-less-than-k/description/
    // O(n) sliding window
    // for all end, find the longest subarray [start,end] whose product<k
    // then for all i in [start,end], subarray [i, end]'s product<k
    
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k==0) return 0;
        int ans = 0, prod = 1, start = 0;
        
        for (int end=0; end<nums.size(); ++end) {
            prod *= nums[end];
            while (start<=end && prod>=k) 
                prod /= nums[start++];
            if (prod<k) ans += end-start+1;
        }
        
        return ans;
    }
};