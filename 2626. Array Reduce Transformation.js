/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    // return nums.reduce(
    //     (accumulator, currentValue) => fn(accumulator, currentValue),
    //     init,
    // );
    let cur = init;
    for (let x of nums) {
        cur = fn(cur, x);
    }
    return cur;
};