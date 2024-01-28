/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var sumIndicesWithKSetBits = function(nums, k) {
    const count = (x) => {
        return Array.from(x.toString(2)).filter((c) => c==='1').length;
    };
    return nums.reduce((tot, x, i) => tot + (count(i)===k ? x : 0), 0);
};