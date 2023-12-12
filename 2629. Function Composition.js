/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    
    // 1. recursion
  // return function(x) {
    //     if (functions.length == 0)
    //         return x;
    //     else {
    //         const fn = compose(functions.slice(1));
    //         return functions[0](fn(x));
    //     }
    // }

    // 2. loop
    // return function(x) {
    //     let ans = x;
    //     for (let fn of functions.reverse())
    //         ans = fn(ans);
    //     return ans;
    // }

    // 3.reverse+reduce
    // return function(x) {
    //     return functions.reverse().reduce((acc, fn) => fn(acc), x);
    // }

    // 4. reduceRight
    return function(x) {
        return functions.reduceRight((acc, fn) => fn(acc), x);
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */