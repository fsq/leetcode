/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} x
 * @return {number[]}
 */
var getSubarrayBeauty = function(nums, k, x) {
    let b = new Array(101).fill(0);
    for (let i=0; i<k-1; ++i) ++b[nums[i]+50];
    let ans = [];
    for (let r=k-1; r<nums.length; ++r) {
        if (r>=k) {
            --b[nums[r-k]+50];
        }
        ++b[nums[r]+50];
        let cur = 0;
        for (let c=0, i=-50; i<=0; ++i) {
            c += b[i+50];
            if (c >= x) {
                cur = i;
                break;
            }
        }
        ans.push(cur);
    }
    return ans;
};