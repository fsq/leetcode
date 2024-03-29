impl Solution {
    pub fn longest_string(x: i32, y: i32, z: i32) -> i32 {
        if x > y {
            (x.min(y+1) + y + z) * 2
        } else {
            (x + y.min(x+1) + z) * 2
        }
    }
}