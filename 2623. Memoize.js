/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    let m = new Map();

    return function(...args) {
        const key = JSON.stringify(args);
        if (m.has(key)) {
            return m.get(key);
        } else {
            const ans = fn(...args);
            m.set(key, ans);
            return ans;
        }
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *   callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */