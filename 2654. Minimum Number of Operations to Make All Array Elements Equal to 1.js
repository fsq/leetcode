/**
 * @param {number[]} nums
 * @return {number}
 */
var minOperations = function(nums) {
    let c1 = 0;
    let ans = Infinity;

    const gcd = (a, b) => {
        if (b===0) return a;
        if (a < b) return gcd(b, a);
        return gcd(b, a%b);
    };

    for (let i=0; i<nums.length; ++i) {
        if (nums[i] === 1) ++c1;
        if (i+1<nums.length) {
            for (let g=gcd(nums[i], nums[i+1]),j=i; j+1<nums.length; ++j) {
                g = gcd(g, nums[j+1]);
                if (g===1) ans = Math.min(ans, Math.abs(i-j)+nums.length);
            }
        }
    }
    if (c1 > 0) {
        return nums.length - c1;
    } else {
        return ans===Infinity ? -1 : ans;
    }
};