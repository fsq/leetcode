/**
 * @param {number} sx
 * @param {number} sy
 * @param {number} fx
 * @param {number} fy
 * @param {number} t
 * @return {boolean}
 */
var isReachableAtTime = function(sx, sy, fx, fy, t) {
    let dx = Math.abs(sx-fx);
    let dy = Math.abs(sy-fy);
    let mn = Math.max(dx, dy), mx = dx + dy;
    if (t===mx+1) return mx>0;
    return t>=mn;
};