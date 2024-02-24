/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximizeSum = function(nums, k) {
    let mx = Math.max(...nums);
    return (2*mx+k-1)*k/2;
};