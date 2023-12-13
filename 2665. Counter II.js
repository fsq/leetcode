/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
class Counter {
    constructor(init) {
        this.origin = init;
        this.x = init;
    }
    increment() {
        return ++this.x;
    }
    decrement() {
        return --this.x;
    }
    reset() {
        return this.x = this.origin;
    }
}
var createCounter = function(init) {
    return new Counter(init);
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */