/**
 * @param {number[]} nums
 * @return {number}
 */
var countWays = function(nums) {
    nums.sort((a,b)=>a-b);
    let s = 0, ans = 0;
    if (nums[0] > 0) ++ans;
    for (let i=0; i<nums.length; ++i) {
        ++s;
        if (s > nums[i] && (i+1===nums.length || s<nums[i+1])) {
            ++ans;
        }
    }
    return ans;
};