/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let ans = [];
    for (let i=0; i<arr.length; i+=size) {
        ans.push(arr.slice(i, i+size, arr.length));
    }
    return ans;
};
