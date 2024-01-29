/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var findIntersectionValues = function(nums1, nums2) {
    let a = new Set(nums1), b = new Set(nums2);
    let ans = [0, 0];
    nums1.forEach((v) => {
        if (b.has(v)) ++ans[0];
    });
    nums2.forEach((v) => {
        if (a.has(v)) ++ans[1];
    });
    return ans;
};