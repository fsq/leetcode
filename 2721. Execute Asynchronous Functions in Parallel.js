/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    // async functions are "not started".
    // fn() turns async functions into a promise (executing once created, in pending state)
    // return Promise.all(functions.map(fn => fn()));
    return new Promise((resolve, reject)=>{
        let ans = new Array(functions.length);
        let cnt = 0;
        for (let i=0; i<functions.length; ++i) {
            functions[i]().then(
                (res) => {
                    ans[i]=res;
                    ++cnt;
                    if (cnt === functions.length) resolve(ans); 
                },
                (e) => { reject(e); });
        }
        return ans;
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */