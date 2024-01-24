/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
    
    return async function(...args) {
        let p1 = fn(...args);
        let p2 = new Promise((resolve, reject) => {
            setTimeout(()=>reject("Time Limit Exceeded"), t);
        });
        return Promise.race([p1, p2]);
        // return new Promise((resolve, reject) => {
        //     let p1 = fn(...args);
        //     let p2 = new Promise((resolve, reject) => {
        //         setTimeout(()=>reject("Time Limit Exceeded"), t);
        //     });
        //     return Promise.race([p1, p2]).then(
        //         (res) => resolve(res),
        //         (err) => reject(err)
        //     );
        // });
    }
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */