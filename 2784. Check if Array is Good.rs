impl Solution {
    pub fn is_good(mut a: Vec<i32>) -> bool {
        a.sort();
        for i in 0..a.len() {
            let target = if i==a.len()-1 {
                i
            } else {
                i + 1
            };
            if a[i] != target as i32 {
                return false;
            }
        }
        true
    }
}