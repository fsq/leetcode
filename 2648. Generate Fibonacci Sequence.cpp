/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
  let [x, y] = [0, 1];

  while (true) {
    yield x;
    [x, y] = [y, x + y];
  }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */