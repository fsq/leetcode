/**
 * @param {number[]} nums
 * @return {number}
 */
var minOperations = function(nums) {
    let m = new Map();
    nums.forEach((x) => {
        m.set(x, m.has(x) ? m.get(x)+1 : 1);
    });
    let ans = 0;
    for (let [k, v] of m) {
        if (v===1) return -1;
        let op = 0;
        if (v % 3 === 0) {
            op = v/3;
        } else {
            op = Math.floor(v/3) + 1;
        }
        ans += op;
    }
    return ans;
};