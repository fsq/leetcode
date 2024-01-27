/**
 * @param {number[][]} nums
 * @return {number}
 */
var numberOfPoints = function(nums) {
    let arr = new Array(101).fill(false);
    nums.forEach((a) => {
        arr = arr.fill(true, a[0], a[1]+1);
    });
    return arr.filter(x=>x).length;
};