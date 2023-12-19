/**
 * @param {number[]} nums
 * @return {void}
 */
var ArrayWrapper = function(nums) {
    this.a = nums.slice();
};

/**
 * @return {number}
 */
ArrayWrapper.prototype.valueOf = function() {
    return this.a.reduce((sum, x) => sum+x, 0);
}

/**
 * @return {string}
 */
ArrayWrapper.prototype.toString = function() {
    // return "[" + this.a.join(',') + "]";
    return `[${this.a.toString()}]`;
}

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */